/*
 * Broadcom WPS module (for libupnp), xml_x_wfawlanconfig.c
 *
 * Copyright 2020 Broadcom
 *
 * This program is the proprietary software of Broadcom and/or
 * its licensors, and may only be used, duplicated, modified or distributed
 * pursuant to the terms and conditions of a separate, written license
 * agreement executed between you and Broadcom (an "Authorized License").
 * Except as set forth in an Authorized License, Broadcom grants no license
 * (express or implied), right to use, or waiver of any kind with respect to
 * the Software, and Broadcom expressly reserves all rights in and to the
 * Software and all intellectual property rights therein.  IF YOU HAVE NO
 * AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE IN ANY
 * WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE ALL USE OF
 * THE SOFTWARE.
 *
 * Except as expressly set forth in the Authorized License,
 *
 * 1. This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof, and to
 * use this information only in connection with your use of Broadcom
 * integrated circuit products.
 *
 * 2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
 * "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR
 * OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 *
 * 3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL,
 * SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR
 * IN ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
 * IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR (ii)
 * ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF
 * OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY
 * NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
 *
 * $Id: xml_x_wfawlanconfig.c 241182 2011-02-17 21:50:03Z $
 */
#include <upnp.h>

char xml_x_wfawlanconfig[] =
	"<?xml version=\"1.0\"?>\r\n"
	"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\r\n"
	"\t<specVersion>\r\n"
	"\t\t<major>1</major>\r\n"
	"\t\t<minor>0</minor>\r\n"
	"\t</specVersion>\r\n"
	"\t<actionList>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>DelAPSettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewAPSettings</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>APSettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>DelSTASettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewSTASettings</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>STASettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>GetAPSettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewAPSettings</name>\r\n"
	"\t\t\t\t\t\t<direction>out</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>APSettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>GetDeviceInfo</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewDeviceInfo</name>\r\n"
	"\t\t\t\t\t\t<direction>out</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>DeviceInfo</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>GetSTASettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewSTASettings</name>\r\n"
	"\t\t\t\t\t\t<direction>out</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>STASettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>PutMessage</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewInMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>InMessage</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewOutMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>out</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>OutMessage</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>PutWLANResponse</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewWLANEventType</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>WLANEventType</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewWLANEventMAC</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>WLANEventMAC</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>RebootAP</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewAPSettings</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>APSettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>RebootSTA</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewSTASettings</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>APSettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>ResetAP</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>ResetSTA</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>SetAPSettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewAPSettings</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>APSettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>SetSelectedRegistrar</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewMessage</name>\r\n"
	"\t\t\t\t\t\t<direction>in</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>Message</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t\t<action>\r\n"
	"\t\t\t<name>SetSTASettings</name>\r\n"
	"\t\t\t\t<argumentList>\r\n"
	"\t\t\t\t\t<argument>\r\n"
	"\t\t\t\t\t\t<name>NewSTASettings</name>\r\n"
	"\t\t\t\t\t\t<direction>out</direction>\r\n"
	"\t\t\t\t\t\t<relatedStateVariable>STASettings</relatedStateVariable>\r\n"
	"\t\t\t\t\t</argument>\r\n"
	"\t\t\t\t</argumentList>\r\n"
	"\t\t</action>\r\n"
	"\t</actionList>\r\n"
	"<serviceStateTable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>WLANResponse</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>WLANEventType</name>\r\n"
	"\t\t\t<dataType>ui1</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>InMessage</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>OutMessage</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>APSettings</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>Message</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"yes\">\r\n"
	"\t\t\t<name>STAStatus</name>\r\n"
	"\t\t\t<dataType>ui1</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>WLANEventMAC</name>\r\n"
	"\t\t\t<dataType>string</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>DeviceInfo</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"no\">\r\n"
	"\t\t\t<name>STASettings</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"yes\">\r\n"
	"\t\t\t<name>APStatus</name>\r\n"
	"\t\t\t<dataType>ui1</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"\t<stateVariable sendEvents=\"yes\">\r\n"
	"\t\t\t<name>WLANEvent</name>\r\n"
	"\t\t\t<dataType>bin.base64</dataType>\r\n"
	"\t</stateVariable>\r\n"
	"</serviceStateTable>\r\n"
	"</scpd>\r\n"
	"\r\n";