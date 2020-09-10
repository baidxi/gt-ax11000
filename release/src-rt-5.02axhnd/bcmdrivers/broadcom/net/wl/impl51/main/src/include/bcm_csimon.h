/*
 * +--------------------------------------------------------------------------+
 * bcm_csimon.h
 *
 * External Interface for Channel State Information (CSI) Monitor module, shared
 * between dongle firmware (producer) and host driver (consumer).
 *
 * Copyright (C) 2020, Broadcom. All Rights Reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * <<Broadcom-WL-IPTag/Open:>>
 *
 * $Id$
 *
 * vim: set ts=4 noet sw=4 tw=80:
 * -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * +--------------------------------------------------------------------------+
 */
#ifndef __bcm_csimon_h__
#define __bcm_csimon_h__

/** Conditional Compiles */
//#define CSIMON_FILE_BUILD       /* Stream to File Support */

/**
 * +--------------------------------------------------------------------------+
 *  Section: BCM_CSIMON Shared Definitions between Dongle and Host
 * +--------------------------------------------------------------------------+
 */

/** Section: BCM_CSIMON Compatability Control <version, release, patch> */
/** 32 bit [ <16 bit version> : <8 bit release> : <8 bit patch> ] */
#define CSIMON_VERSION              (1)
#define CSIMON_RELEASE              (0)
#define CSIMON_PATCH                (0)
#define CSIMON_VERSIONCODE          \
	(((CSIMON_VERSION) << 16) + ((CSIMON_RELEASE) << 8) + ((CSIMON_PATCH) << 0))

/** Version Release Patch: Dot Notation Form */
#define CSIMON_VRP_FMT              " %s[%u.%u.%u]"
#define CSIMON_VRP_VAL(vercode)     "CSIMON", \
	                                (((vercode) >> 16) & 0xFFFF), \
	                                (((vercode) >>  8) & 0x00FF), \
	                                (((vercode) >>  0) & 0x00FF)

/** Format ID / version for the CSI report generated by PHY layer */
/** User application should use this */
#define CSI_REPORT_FORMAT_ID 0

/** BCM_CSIMON Stream to File Support */
#define CSIMON_FILENAME             "/var/csimon"
#define CSIMON_FILESIZE             (1 * 1024 * 1024) /* max filesize */
#define CSIMON_FILE_OPEN_FAIL_LIMIT 32

/** BCM_CSIMON Host Side Polling Interval */
#define CSIMON_POLL_10MSEC_TICKS    (5)   /* 5 * 10 millisec = 50 millisec */

/** BCM_CSIMON Ring Memory */
#define CSIMON_RING_ITEM_SIZE       (2048)  /* Maximum size of CSIMON element */
#define CSIMON_RING_ITEMS_MAX       (32)
#define CSIMON_RING_MEM_BYTES       \
	(CSIMON_RING_ITEM_SIZE * CSIMON_RING_ITEMS_MAX)

/** Section: BCM_CSIMON PCIE IPC Shared Structure */
/** Preamble's write and read index, must be cacheline aligned */
#define CSIMON_ALIGNMENT            (64)
#define __csimon_aligned            __attribute__ ((aligned (CSIMON_ALIGNMENT)))

/** Circular Ring write and read index */
struct csimon_ring_idx {
	uint32  u32;
} __csimon_aligned;
typedef struct csimon_ring_idx csimon_ring_idx_t;

/** Each CSIMON structure posted from Dongle into the circular ring */
struct csimon_ring_elem {
	uint8   data[CSIMON_RING_ITEM_SIZE];    /* Actual data may be smaller */
} __csimon_aligned;
typedef struct csimon_ring_elem csimon_ring_elem_t;

/** CSIMON Preamble context */
struct csimon_preamble {
	uint32              version_code;       /* CSIMON <version,release,patch> */
	uint32              elem_size;          /* size of csimon_ring_elem */
	uint32              table_daddr32;      /* ring base of csimon_elem_t */
	csimon_ring_idx_t   write_idx;
	csimon_ring_idx_t   read_idx;
} __csimon_aligned;
typedef struct csimon_preamble csimon_preamble_t;

/** CSIMON PCIE IPC shared structure in Host Memory Extension (HME) */
typedef struct csimon_ipc_hme {
	csimon_preamble_t   preamble;
	/* Table of CSI records; has a guard zone of the same size */
	/* The guard zone is a temporary measure to avoid the corruption in that
	 * host memory area right after the CSIMON ring. It's still under
	 * investigation.
	 */
	csimon_ring_elem_t  table[CSIMON_RING_ITEMS_MAX * 2];
} csimon_ipc_hme_t;

/** Section: BCM_CSIMON HME Sizing */
#define CSIMON_IPC_HME_BYTES        (sizeof(csimon_ipc_hme_t))

/** Section: BCM_CSIMON Helper Macros */
/** Compute an element index, given a table base and an element pointer */
#define CSIMON_TABLE_ELEM2IDX(table_base, elem) \
	((int)(((struct csimon_ring_elem *)(elem))   \
	     - ((struct csimon_ring_elem *)(table_base))))

/** Compute an element pointer, given a table base and the element's index */
#define CSIMON_TABLE_IDX2ELEM(table_base, idx) \
	(((struct csimon_ring_elem *)(table_base)) + (idx))

#if defined(DONGLEBUILD)

#define CSIMON_DEFAULT_TIMEOUT_MSEC      (50)	// 50 millisecs

extern int  pciedev_csimon_dump(void);

#endif /* DONGLEBUILD */

#endif /* __bcm_csimon_h__ */