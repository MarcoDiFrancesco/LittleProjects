# Networks

## Protocol

What's a protocol? Protocols define format, order of msgs sent and received among network entities, and actions taken on msg transmission, receipt.

The **components of a protocol** are:

- syntax: format of the protocol messages
- semantics: meaning of the messages
- temporization: timeouts fot acknowledgements

**ADSL**: asymmetric digital subscriber line

**Throughput**: rate (bits/time unit) at which bits transferred between sender/receiver, this is limited to the slower link capacity (bottleneck).

The **protocols** are used make a logical and physical connection between architectures. The protocols are devided in layers, so complex systems can be splitted in more simple system's pieces so it makes the update easier.

App-layer **protocols** (e.g HTTP, SMTP) allow types of messages to be exchanged with a specific semantic. Rules are specidied for each protocol. Protocols can be open like HTTP, SMTP or proprietary like Skype.

**Protocol stack** is a collection of protocols and of their relationships defining a logical and pysical communication architecture.

Every **layer** of a protocol stack is composed by 2 sub-systems, every **sub-system** is composed by **entities**.

![https://i.imgur.com/jDRKccf.png](https://i.imgur.com/jDRKccf.png)

Every layer provides services to the **upper layer** throgh a **Service Access Points**. A SAP is the "API" of the stack, in which layers communicate. Layer N+1 only knows that lower layers offer an N-service and what is below it, is a black box.

![https://i.imgur.com/RD39eed.png](https://i.imgur.com/RD39eed.png)

In a system with M layers:

- The **service data unit** (SDU) is the "packed" piece of data received from the layer above
- The **protocol control information** (PCI) is the piece of data attached to the SDU containing the receiver and sender addresses
- The **protocol data unit** (PDU) is the result of SDU + PCI, and it is passed to the layer below

## Segmentation and reassembling

The PDU can be:

- **segmented** when the block is too large to be transported
- **assembled** when the blocks are too small to be transported, so they are bundled togeder
- **re-assembled** after the sagmented blocks have been received

## Internet protocols

ISO/OSI vs TCP/IP:

The **International Organization for Standardization** created the **Open System Interconnection** model (ISO/OSI), it is an abstract model.

The Internet protocol suite is the conceptual model and set of communication protocols used in the internet. It's known as TPC/IP because the of its fundamental protocols: **Transmission Control Protocol** (TCP) and **Internet Protocol** (IP).

![https://i.imgur.com/3JxVCxD.png](https://i.imgur.com/3JxVCxD.png)

![https://i.imgur.com/RAbVT6O.png](https://i.imgur.com/RAbVT6O.png)

ISO/OSI procols:

![ISO/OSI](https://i.imgur.com/c5rDXCK.png)

Layer 7: **Application** provides to the applications the means to communicate and exchange data, e.g. FTP, SSH, POP3, IMAP, SMTP, HTTP, DNS, SSH .

Layer 6: **Presentation** makes encryption, data rappresentation (encoding). Some procols are: MIME, ASCII.

Layer 5: **Session** Manages data exchange so this can be paused, restared and terinated. For example if a whatsapp call changes from wifi to cellular the layer manage not to disconnect.

Layer 4: **Trasport** makes the application [multiplexing and demultiplexing](#multiplexing-and-demultiplexing), performs [segmentation and reassembles](#segmentation-and-reassembling) data, error control, flow control, packet ordering. Some example protocols are: TCP, UDP. Here packets are called **datagrams** (and rarely segments).

Layer 3: **Network** (OSI) or **Internet** (TCP/IP) makes routing and forwarding, congestion control. It can make the routing in two ways: connection-less in which each packet is sent indipendently, and connection-oriented in which the route is establiched once, and used for all packets belonging to a specific host to host communication. Some example procols are: IP (IPv4, IPv6), [ICMP](#ICMP). Here packets are called **datagrams** (and rarely packets).

Layer 2: **Data link** (OSI) or **Link** (TCP/IP) makes the [multiplexing and demultiplexing](#multiplexing-and-demultiplexing) of layer 3 protocols, error discovery and recovery, medium access control (MAC sublayer). Some example protocols are: DSL, 802.11 (Wireless), 802.3 (Ethernet), [ARP](#ARP). Here packets are called **frames**. Exaplained in details [below](#data-link)

Layer 1: **Physical** is in the bottom of the model. It takes care of transmitting raw bits on the interface via electrical, electro-magnetic, light, sound ways signals. It defines encoding, voltages, modulations. Here packets are **bits**.

## Structure of the internet

**ISP** (internet service provider) connects the end systems to internet. The ISPs are interconnected so that and two hosts can send packets to each other.
The ISPs can be devided in categories:

- **Tier-3**: **Access ISP** make the last mile communication (ADSL providers)
- **Tier-2**: **Regional** networks like Telecom, Vodafone are connected to one or more Tier-1 ISPs and **internet exchange points** (IXPs)
- **Tier-1**: networks like AT&T connect distant networks, like networks located in different continents

In Tier-1 there can also be **content provider** networks like Google and Microsoft, which run their (private) network to bring their services close to the end user.

ISP networks:

![https://i.imgur.com/cQf9Ke6.png](https://i.imgur.com/cQf9Ke6.png)

## Network architectures

The **client-server** architecture makes the server always-on host, servers have permanent IP addresses, the clients do not communicate directly with each other.

The **P2P** architecture, like torrent, make the end systems communicate directly, the con of the P2P architenture is that the management of the network is complex.  
The communication client-server and P2P is done through **sockets** that works like doors. Each layer use sockets to communicate with the layer above and below.

The P2P architecture works with communication between peers. Known examples are Skype and BitTorrent. BitTorrent protocol devides packets with size from 32 kB up to 16 MB the files that want to transmit. The IP list can be asked to the neighborns and the available chunks they have.

**Process** is a program running within a host. **Inter process commnication** the fact of exchanging messages.

The **transport service** of an application can require some needs:

- **Data integrity**: a downloaded file requires 100% reliable data transfer
- **Timing**: phone call or gaming requires low latancy, if there is some data lost it's not that big problem
- **Throughput**: video streaming requires large throughput, losing data in this case is not a big ploblem
- **Security**: emails require enctyption and data integrity

## HTTP

The **web** procol HTTP allows exchange of pages consisting of objects like HTML files, JPEG images, audio files. The connection in HTTP make a request and receive a response. This connection is manages by the browser. The connection over TCP is initiated creating a socket in the 80 port and communicates over HTTP messages and then it closes the connection.

In HTTP the connection is **state-less**, it does not mantain any information about the previous client requests.

The HTTP can be **persistent** ot **non-persistent**: it's non-persistent when it doens't mantain the TCP connection, so when openening a new request every time it asks for a file. It's persistent when multple objects can be sent over a single TCP connection.

Non-persistent HTTP response time = 2\*RTT + file transmission time.

**HTTP** handles two types of messages: requests and responses. The request message is encoded in ASCII so it's human readable. An example of a **GET Request**:

```HTTP
GET /index.html HTTP/1.1\r\n
Host: www-net.cs.umass.edu\r\n
User-Agent: Firefox/3.6.10\r\n               # Browser
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us,en;q=0.5\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8;q=0.7\r\n
Keep-Alive: 115\r\n
Connection: keep-alive\r\n                   # Persistent or non-persistent
\r\n
```

An example of a **GET Response**:

```HTTP
HTTP/1.1 200 OK\r\n
Date: Sun, 26 Sep 2010 20:09:20 GMT\r\n
Server: Apache/2.0.52 (CentOS)\r\n
Last-Modified: Tue, 30 Oct 2007 17:00:02 GMT\r\n
ETag: "17dc6-a5c-bf716880"\r\n
Accept-Ranges: bytes\r\n
Content-Length: 2652\r\n
Keep-Alive: timeout=10, max=100\r\n
Connection: Keep-Alive\r\n
Content-Type: text/html; charset=ISO-8859-1\r\n
\r\n
data data data data data ...
```

The version 1.1 of HTTP has:

- GET
- POST
- HEAD asks server only the head
- PUT uploads file in entity body to path specific in URL field
- DELETE which deletes file specified in the URL field

Some of the HTTPS response status codes are:

- 200 OK
- 301 Permanently moved
- 400 Bad request
- 404 Not found
- 505 HTTP version not supported

## Cookies

The are 4 main types of **Cookies**: cookies header line of HTTP response meassage (Susan always access internet from PC), cookie header line in next HTTP request message (she visits specific e-commerce site fo the first time), cookies file kept on a user's host manages by the browser (to give unique ID in a login so that in refres the browser doesn't log out) and back-end database at Web site (website tracks the user shopping list).

Cookies:

![https://i.imgur.com/DZ42h5b.png](https://i.imgur.com/DZ42h5b.png)

## Proxy server

**Proxy servers** are used to cache a certain web page. For example if a user in the university (using the university's proxy server) request a static page from a web server the proxy server saves it, so in case another user request it, the proxy server won't reach it another time.  
Proxy server acts as both client and server, in the server side a preprocessed page can be given to a user if he requests it in short period of times.

In HTTP there is also the **conditional GET**, it doesn't sent object if cache has up-to-date cached version:

![https://i.imgur.com/f2VcYzK.png](https://i.imgur.com/f2VcYzK.png)

## Email protocols

**SMTP** (Simple Mail Transfer Protocol) is mostly used for sending out email from an email client (e.g. Microsoft Outlook, Thunderbird or Apple Mail) to an email server. It's also used for relaying or forwarding mail messages from one mail server to another. TCP to transer email messages through port 25 with persistent connections, 587 and port 465.

**POP3** (Post Office Protocol) is stateless across sessions and has 2 modes "downloads and delete" (by default) and "download and keep" emails (not used because there is IMAP).

**IMAP** (Internet Mail Access Protocol) stores the email always in a mail server, it allows users to group related messages and place them in folders, which can in turn be arranged hierarchically. It's also equipped with message flags that indicate whether a message has been read, deleted, or replied to. It even allows users to carry out searches against the server mailboxes:

![https://i.imgur.com/dtiVb7r.png](https://i.imgur.com/dtiVb7r.png)

## DNS

DNS (Domain Name System) makes the translation from hostname to IP address. A problem of DNS is that has a single point of failure so does not scale:

![https://i.imgur.com/ScGAE4J.png](https://i.imgur.com/ScGAE4J.png)

The **DNS root name** servers are 13 in all the world and return the mapping to local name servers.

The **Top-Level Domain** (TLD) servers are responsible for com, org, net, edu, aero, jobs, museums, and all top-level country domains, e.g.: uk, fr, ca, jp.

The **local DNS** is owned by the ISP and it's the first DNS contacted by a user. Local DNSs do not belong to hierarchy.

The DNS can cache the recods with a TTL so the TLD are not so often visited.

Some types of domains are: A (normal), CNAME (alias), NS (domain name), MX (mail server).

## LDAP

LDAP (Lightweight directory access protocol) is used to store recors (like DNS) and is meant to be easy to query.

![LDAP](https://i.imgur.com/aqrgh7L.png)

## CDN

The **content distribution network** are used to scale the availability of data to more servers.

The **DASH** (Dynamic, Adaptive Streaming over HTTP) streams multimedia so that the server the effort is divided in multiple CNSs. The server devides video file into multiple chunks, is encoded at different rates, and creates the manifest file contains URLs for the different chunks. The clint checks the bandwidht and consult the manifest to get the more appropiate chunk. The client can check for the closest CDN and the resolution wanted.

## Transport layer protocols

There are two main internet transport protocol services TCP and UDP.

TCP (Transmission Control Protocol) architecture is reliable. It is **connection-oriented** so a setup between two hosts is required:

Provides:

- multiplexing and demuliplexing
- incapsulation at application level
- **point-to-point** because there is one sender and one receiver
- **in-order delivery**
- **congestion control** adapting the transmission rate depending on the newtork conditions
- **flow control**
- **bi-directional** data flow

Does **not** provide:

- timing
- minimum throghput
- security

The UDP protocol exists beacause it's not possible to use just IP protocol bacause it doesn't use any port. UDP is a **best effort**, this means it establishes an **unreliable data tranfer** service, so segments may be lost or delivered out of order. UDP (User datagram protocol) architecture:

Provides:

- multiplexing and demuliplexing
- incapsulation at application level

Does **not** provide:

- **ordered delivery** so the packeckes may be out of order
- **handshake** between sender and receiver
- reliability (packets may be **lost**)
- flow control
- congestion control
- timing
- minimum throghput
- security

UDP , this means that segments may be lost or delivered out of order, there is not reliability on when a datagram is transfered.

TCP and UDP **can be encrypted** using SSL/TLS to ensure **data integrity** and **end-point authetication**.

## Multiplexing and demultiplexing

**Multiplexing**: gathering data from multiple sockets (sent by processes), add the port to the transport header, enveloping header and packet togheder and sending them as a whole to the intended receiver.

**Demultiplexig**: watch the transport header to understand to which app layer processes the packet needs to be sent and delivering it there.

The ports in the segment are 16 bit integers, with well defined ports up to 1024 and non standard ports up to 65535. Ports are of 2 types:

- **static** associated with standard applications (emails, web, DNS)
- **dynamic** assigned by the operating system when opening a connection or creating a socket

![https://i.imgur.com/mdIMnc7.png](https://i.imgur.com/mdIMnc7.png)

![https://i.imgur.com/EtdWsg7.png](https://i.imgur.com/EtdWsg7.png)

## ARQ

**Automatic Repeat reQuest** (ARQ) is a class of protocols that deals with packet loss, and it's made to notify the transmitter of the reception using acknoledgments.

Some ARQ protocol examples are:

- Stop and wait
- Go-back-N
- Selective Repeat
- TCP
- WiFi-s MAC protocol

## Stop and wait

The flow from the **transmitter prospective** is:

- send PDU
- set timeout
- wait for acknoledgement
- if not ack is received
  - within timeout resend PDU
- if ack is receided
  - make checksum
  - if correct send next PDU

The flow from the **receiver prospective** is:

- make checksum of PDU
- check sequence number
- if correct and in order
  - send ACK
  - pass SDU to upper layers
- if checksum or sequence number incorrect
  - drop PDU

![https://i.imgur.com/sJREwAr.png](https://i.imgur.com/sJREwAr.png)

Stop and wait example:

Using stop and wait there will be the following efficiency:

![https://i.imgur.com/QWbfBTE.png](https://i.imgur.com/QWbfBTE.png)

## Pipelined protocols

Pipelining increases utilization of the bandwidth. So instead of sending 1 at a time like Stop and wait, multiple packets are sent before receiving the ACK.

Legend:

`RTT` is the **Round Tript Time**, the time to travel from client to server and back (does not count file transmission time from the sender, so time starts when the packet has been uploaded).

`L` is the **packet size**

`N` is the **window**, the number of packets that is possible to send per RTT.

`Wt` is the **transmission windows**, the number of PDUs that the transmitter is allowed to transmit without receiving an ACK, the Wt has also the following:

- `Wlow` is the **low pointer**, the first packet in the transmission window
- `Wup` is the **up pointer**, the last packet in the transmission window

`|Wt|` is the **size of the window**.

`Wr` is the **receive windows**, the number of PDUs that the receiver is capable to accept and memorize.

Here `thoughput = 3 x L / RTT`, generally `throughput = N x L / RTT`:

![https://i.imgur.com/Tf0ZtYC.png](https://i.imgur.com/Tf0ZtYC.png)

## Acknoledgements

There are different types of ACKs:

- **individual ACK** that indicates the correct reception of a specific packet `ACK(n)`
- **cumulative ack** indicates the correct reception of ACKs up to a certain packet. `ACK(n)` means I received everythink up to packet n (not included)
- **neative ACK** (NACK) request retrasmission of a single packet `NACK(n)`
- **piggybacking** means inserting ACK data into a packet

Pipelined protocols examples are Go-back-N and Selective repeat.

## Go-back-N and Selective repeat

The main difference between the two protocols is that the first one, if it gets an ACK that is not exactly in order, it rejects everything else except the expected packet, and in selective repeat the packets that are not exactly in order, they get accepted anyway (if the receiver window is big enough).

**Go-back-N**: if a packet fails the sender will send continuously the previous arrived ACK and receiver will wait for timeout of the missed packet.  
`|Wr| = 1`

![https://i.imgur.com/9qs1Jsj.png](https://i.imgur.com/9qs1Jsj.png)

**Selective repeat**: if a packet failes the sender will send anyway the ACK for received packets and receiver will wait for timeout of the missed packet.  
`|Wr| = 4`

![https://i.imgur.com/Ea0v9Gl.png](https://i.imgur.com/Ea0v9Gl.png)

The **main problem** with these 2 protocols is that if the receiver gets the packet and the send does not receive the ACK, when there will be a timeout the sender will send the packet and the receiver will accept it as a new packet.

![https://i.imgur.com/Fn4bvVA.png](https://i.imgur.com/Fn4bvVA.png)

## TCP

**Wr** is a 16-bit field with max value 65536 bytes  
Default **MTU** (Maximum Transfer Unit) = 1500 bytes  
Default **MSS** (Maximum Segment Size) = 1500 bytes - 40 bytes (MSS - header)  
Retrasmission time out (RTO)

Some important flags are:

- **SYN** flag synchronizes sequence numbers to initiate a TCP connection
- **FIN** flag indicates the end of data transmission to finish a TCP connection
- **RST** flag to close connection immediately

![TCP structure](https://i.imgur.com/lPEgGJq.png)

**TCP connection setup** is called "three-way handshake".

Sequence:

- host A sends SYN (with port A, port B and initial sequence number x).
- host B sends SYN + ACK (with port B, port A and initial sequence number y).
- host A sends segment (with ACK with port A, port B).

Connection setup:

![https://i.imgur.com/LaBzWnQ.png](https://i.imgur.com/LaBzWnQ.png)

TCP doesn't send single byte (if not forced), it tries to send segments as large as MSS. The MSS is chosen with "Trial and error" mechanism.

The **default MSS** = 1460 bytes (1550 MTU - 40 header)  
The **minimum MSS** = 536 bytes (given by IP protocol)

**TCP finishing procedure polite way**:

- A sends FIN (ask to finish), B sends FINACK (understood that you want to finish)
- B can still send data to A
- B sends FIN (ask to finish), A sends FINACK (understood that you want to finish)

![https://i.imgur.com/PtPE3Bi.png](https://i.imgur.com/PtPE3Bi.png)

**TCP finishing procedure rude way**: one party sends RST flag, the other one does not respond.

## Round trip time

In TCP to calculate the timeout the RTT must be known. In fact `RTT < Timeout`.

**Smothed RTT** makes an average of the previous RTTs.

`SRTT = ( previous SRTT ) + alpha * RTT`  
`SRTT = (1 - alpha) *SRTT + alpha * RTT`

Typical value: alpha = 0.125

![SRTT](https://i.imgur.com/CK4KZ2v.png)

**Retrasmission timeout** is calculated as: `RTO = SRTT + (safety margin)`

**TCP flow control**: receiver “advertises” free buffer space by including RWND value in TCP header so sender limits amount of unacked(“in-flight”) data to receiver’s RWND value.

## Congestion control

**TCP congestion control** means "too many sources sending too much data too fast for network to handle". To deal with congestion control multiple algoritmhs have been proposed over the years, there isn't only one TCP impelementation.

**AIMD** is one implementation of congestion control. The approch: sender increases transmission rate (window size by 1 MSS every RTT), until loss occurs (cut window in half). For example:

![https://i.imgur.com/JVFEH2r.png](https://i.imgur.com/JVFEH2r.png)

AIMD allows fairness in the connection. For a bandwidth R and K sessions there is an average rate of `R/K`.

The CWND (congestion window) in TCP is the number of bytes the transmitter is allowed to inject in the network. There are multiple ways of setting the CWND:

- **slow start, congestion avoidance** in case of few losses
- **fast retransmit, fast recovery** to increase efficience in case of losses

In all cases CWND (Congestion) is **upper bounded** by the Wr. `|WT| = min(CWND, |Wr|)`

## Slow start with Congestion avoidance

**Slow start** to start the connection, when CWND reaches SSTHREASH (slow start threshold) switch to congestion avoidance. Slow start implementation:

- start
  - CWND = 1 MSS
- on valid ACK
  - CWND = CWND \* 2
  - if CWND >= SSTHRESH -> switch to Congestion Avoidance
- on RTO timeout
  - retransmit the missing segment (in slow start) with CWND not counted in the following step
  - CWND = 1 MSS
  - SSTHRESH = max(CWND/2, 2)
  - RTO = RTO \* 2
  - restart in slow start

Slow start example:

![https://i.imgur.com/P4nGi3k.png](https://i.imgur.com/P4nGi3k.png)

**Congestion avoidance** is used once CWND reaches SSTHREASH. Basically, for every RTT in which CWND ACKs are received, increase CWND by 1 MSS.

For every valid ACK received:

- CWND = CWND + 1 MSS
- Send min(CWND, |Tw|)

On RTO timeout:

- slow start RTO timeout

Basically for every RTT in which CWND ACKs are received increase CWND by 1 MSS

Congestion avoidance example:

![https://i.imgur.com/L14zVT8.png](https://i.imgur.com/L14zVT8.png)

## Fast retransmit and fast recovery

Fast recovery idea is: if the network is working try to contunue transmitting.

On 3rd duplicated ack:

- Send missing pachket
- SSTRESH = CWND / 2
- CWND = SSTRESH + 3 MSS

On additional duplicated ACK

- CWND = CWND + 1 MSS
- if CWND allows send new segments

On new ACK

- CWND = SSTHRESH
- swith to congestion avoidance

On partial ACK

- retransmitting first anacknowleged segment
- SWND = CWND - amount of unacknoledged data +1

![Fast recovery example](https://i.imgur.com/8bD100W.png)

## Slow start only vs Fast retransmit and Fast recovery

Slow start only:

![https://i.imgur.com/d8HFH16.png](https://i.imgur.com/d8HFH16.png)

Fast retransmit and recovery:

![https://i.imgur.com/ZCEpQ81.png](https://i.imgur.com/ZCEpQ81.png)

UDP vs TCP fairness is not balanced. UDP does not have congestion control e.g. for multimedia. TCP having congestion control allows multiple parallel connection between two hosts.

## Network layer

There are 2 different logics for the networking layer:

- **data plane** determines how datagram arriving on a router input port is forwarded to router output port, works in hardware of routers in nanoseconds.
- **control plane** determines how datagram is routed among routers along end-end path from source host to destination host, works in software of router in milliseconds.

**Switching fabrics** allows to transfer packet from input buffer to appropriate output buffer.  
**Switching rate**: rate at which packets can be transfer from inputs to outputs.

Different types of swiching fabrics:

![https://i.imgur.com/lIZEWAz.png](https://i.imgur.com/lIZEWAz.png)

In network layer there is the important choice to make on **network neutrality**. If in a router for the packets there is a queue, then a choice to process a packet before another can be made. This raises the problem that if a company is capable of paying the ISP more than another, this company will have access to faster connections. Normally the **scheduling algorighm** should be FIFO, but in real world there is a priority queue.

## IP

**IP** (Internet Protocol)

The IP datagram contains:

- **Total lenght** 16-bit integer that specifies the total number of bytes including header and the data
- **Identification** 16-bit sequential number used for reassemly
- **TTL** (Time To Live) 8-bit integer initiliazed by the sender (max 256 hops), when is 0 the datagram is discarded
- **Header checksum** 16-bit ones-complement checksum of header fields
- **Source Ip Address** 32-bit Internet address of the original sender
- **Source Ip Address** 32-bit Internet address of the ultmate destination
- **Is fragmented** 1-bit that says if a datagram is fragmented
- **Fragmented Offset** specifies where in the original datagram the fragment belongs

## IP fragmentation

**MTU** (Maximum Transmission Unit) maximum amount of data that a frame can carry given by the hardware technology.

In a network where there are 2 different MTUs, if a sender has an MTU of 1500 octects and the receiver 1000, then the datagram fragmentation can split the datagram to work with the receiver network.

Reassembling a datagram example with packets sent from H1 to H2 (picture below): if host H1 sends a 1500-octet datagram to host H2, router R1 will divide the datagram into two fragments, which it will forward to R2, router R2 does not reassemble the fragments, it uses the destination address in a fragment to forward the fragment as usual, the ultimate destination host, H2, collects the fragments and reassembles them.

![https://i.imgur.com/IQstOCs.png](https://i.imgur.com/IQstOCs.png)

This has some implications: by postponing reassembly until the ultimate destination IP is free to pass some fragments from a datagram along different routes than other fragments; reduces the amount of state information in routers, a router does not need to know whether the datagram is a fragment or a complete datagram. But if the receiver loses a fragment of a datagram (or expires), this will be discarded.

IP fragmentation is anyway **mostly disabled** for the reasons: firewalling requiring TCP/UDP header inspection, overlapping fragment offset attacks in stateless firewalls, memory exhaustion attacks (DDoS) by intentionally omitting fragments, bad implementations of the reassembly procedure exploited for buffer overflows that means remote code execution attacks.

## IPv4

When sending a packet across the Internet, sender’s protocol software must specify: its own 32-bit IP address and the address of the intended recipient. Routers only use the destination address for forwarding and routing.

**Dotted decimal addresses** range 0.0.0.0 through 255.255.255.255.

IPv4 class addressing, the green part is the prefix, the red part is the suffix:

![https://i.imgur.com/hK6wXvi.png](https://i.imgur.com/hK6wXvi.png)

The **subnet mask** is used to make the operation efficient:

![https://i.imgur.com/6rFe1qu.png](https://i.imgur.com/6rFe1qu.png)

Private IPs:

- 10.0.0.0 to 10.255.255.255 (10.0.0.0/8)
- 172.16.0.0 to 172.31.255.255 (172.16.0.0/12)
- 192.168.0.0 to 192.168.255.255 (192.168.0.0/16)

## Special network addresses

**Network**: all zeros after mask (e.g. 128.211.0.16/28 = 10000000 11010011 00000000 0001**0000**)

**Broadcasting** that means send to all, all 1s are used (e.g. 10000000 11010011 00000000 0001**1111**)

**Limited broadcast** refers to a broadcast on a directly-connected network. It is used during system startup by a computer that does not yet know the network number. Informally, we say that the broadcast is limited to a “single LAN” meaning that it will never be forwarded by a router. All 32 bits are 1s: **11111111 11111111 11111111 11111111**.

A computer obtains its IP address (using DHCP) uses all 0s as IP to communicate **00000000 00000000 00000000 00000000**.

**Loopback address** used to test network applications. e.g., for preliminary debugging after a network application has been created. A programmer must have two application programs that are intended to communicate across a network, instead of executing each program on a separate computer the programmer runs both programs on a single computer and instructs them to use a loopback address when communicating. During loopback testing no packets ever leave a computer, the IP software forwards packets from one application to another. IP serverves the network prefix 127/8 (so 01111111 **00000000 00000000 00000000**).

**Multicast address** means send a packet to a group of hosts, in internet multicast is normally blocked. In IPv4 they start with 1110, so 224.0.0.0 to 239.255.255.255 (1110**0000 00000000 00000000 00000000**).

Subnet reserved to enable local communication when hosts **cannot find an IP** address: 169.254.0.0/16. Each host randomly chooses one IP from that subnet.

## CIDR

**CIDR** (Classless Inter-Domain Routing) is used to devide the network not following classes convention. An exmaple is: suppose the ISP has 2 customers, one customer needs 12 IP addresses and the other needs 9. The ISP can assign:

- customer1 CIDR: 128.211.0.16/28
- customer2 CIDR: 128.211.0.32/28
- both customers have the same mask size (28 bits), the prefixes differ

One problem can araise with multiple entries match: router has 2 netmasks, so it performs 2 matches

- 200.23.19.7 & 255.255.240.0 (/20) = 200.23.16.0 so MATCH
- 200.23.19.7 & 255.255.254.0 (/23) = 200.23.18.0 so MATCH!

In this case the longest prefix match is taken, so /23 is taken.

If there is no match with all the masks, the match is done with 0.0.0.0 at the end of the table.

![https://i.imgur.com/Uj9mVV6.png](https://i.imgur.com/Uj9mVV6.png)

## NAT

NAT (Network Address Translation) uses a 16-bit port number field to store outside connections. When a user inside a network request an outside connection the NAT adds a record to the table with the incoming request port and the outside port. If a user wants to skip NAT the procolo UPnP or port forwarding needs to be set.

![https://i.imgur.com/YdOgw5n.png](https://i.imgur.com/YdOgw5n.png)

## ARP

**ARP** (Address Resolution Protocol) is a link layer protocol that allows a host to resolve addresses in the same physical network. ARP example: suppose B needs to resolve the IP address of C, B broadcasts a request that says: “I'm looking for the MAC address of a host that has IP address C”. An ARP request message reaches all computers on a network, when C receives a copy of the request it sends a directed reply back to B that says: “I'm the computer with IP address C, and my MAC address is M”:

![https://i.imgur.com/ZBVMweO.png](https://i.imgur.com/ZBVMweO.png)

## ICMP

**ICMP** (Internet Control Message Protocol) is used to report errors back to the original source. IP and ICPM are co-dependent, IP depends on ICMP to report errors, ICMP uses IP to carry error messages. When a router wants to send an ICMP message, creates an IP datagram and encapsulates the ICMP message in it. ICMP messages do not have special priority. If an ICMP error message causes an error, no error message is sent.

**Traceroute command** send IP datagrams with increasing TTL (1, 2, 3, ...), with TTL = 1 the first router changes the TTL to 0, datagram gets dropped, router (should) sends a Time Exceeded message back with own IP address. With TTL = 2, first router changes the TTL to 1, second router to 0, repeat until destination reached, used to understand the path traveled.

## DHCP

**DHCP** (Dynamic Host Configuration Protocol) dynamically assigns IP by a server when joining and allows re-use of addresses.

DHCP **issues a lease** on the address for a finite period. The use of leases allows a DHCP server to reclaim addresses. When the lease expires the server places the address to the pool of available addresses. When a lease expires, a host can choose to relinquish the address or renegotiate with DHCP to extend the lease, negotiation occurs concurrent with other activity.

DHCP can **return**: address of first-hop router for client, name and IP address of DNS server, network mask. If no DHCP is set up, then link-local address can be used and manual IP configuration is required.

The process of getting a new ip using DHCP is:

- **DHCP discover** when host sends in broadcast the message
- **DHCP offer** is the message sent by the DHCP server to the clint (says I'm here)
- **DHCP request** is the message sent by the host to request a DHCP (says I need a IP)
- **DHCP ack** is the message sent by the server with the new IP (says that's your IP)

## IPv6

IPv6 has an address of 128 bits, 16 bits blocks, colon separated (e.g. **2a03:2880:f108:0083:face:b00c:0000:25d**). The changes from IPv4 are:

- no fragmentation allowed
- checksum: removed entirely to reduce processing time at each hop
- ARP is provided by Neighbor Discovery Protocol

Not all routers can be upgraded simultaneously, no “flag days” how will network operate with mixed IPv4 and IPv6 routers? This is done through tunneling: IPv6 datagram carried as payload in IPv4 datagram among IPv4 routers:

![https://i.imgur.com/t1iR9MS.png](https://i.imgur.com/t1iR9MS.png)

## Network paths

**Graph**: G = (N, E)  
**Nodes** (router): N = {u, v, w, x, y, z}  
**Links**: E = {(u,v), (u,x)}  
**Cost**: c(w, z) = 5  
**Path cost**: cost (x1, x2, ..., xp) = c(x1, x2) + c(x2, x3) + ... + c(xp-1, xp)

![https://i.imgur.com/1l8PvOX.png](https://i.imgur.com/1l8PvOX.png)

## Link-state algorithms

**Dijkstra** is a link-state routing algorithm, it has a costs of O(n^2). Legend: cost is D(v), predecessor node is p(v). An example is:

![https://i.imgur.com/b5UwM5T.png](https://i.imgur.com/b5UwM5T.png)

With a restulting **forwarding table**:

![https://i.imgur.com/PRn20QU.png](https://i.imgur.com/PRn20QU.png)

One problem of Djkestra can raise with network oscilalations, for example:

![https://i.imgur.com/KqDtd94.png](https://i.imgur.com/KqDtd94.png)

**OSPF** (Open Shortest Path First) is another link-state routing protocol, topology known by all nodes, routes are computed using Dijkstra's algorithm. An AS (Autonomous system) is a serie of routers that are bundled togheder. Within the AS, routers use flooding advertisement to all other routers.

OSPF implements three procedures:

- **Hello protocol** periodic messages to check for working links (maintain neighbors)
- **Exchange protocol** used to exchange the known network topology between neighbors that just discovered each other
- **Flooding protocol** used to inform all routers in the AS of a link state change

OSPF has an hierarchy, link-state advertisement is done only in the AS:

![https://i.imgur.com/KRbCNkL.png](https://i.imgur.com/KRbCNkL.png)

## Distance vector routing

**Distance Vector** (DV) algorithms are distributed routing algorithm where there is no knowledge of the whole network, but only the knowledge of direct neighbors.

**Bellman Ford** is a basic Distance Vector algorithm. Some caracteristics are: each router knows networks directly attached to it, routers advertise IP addresses, we use router IDs as destinations (but in reality you have addresses).

That's how the Distance Vector (using Bellman Ford) algoritm works:

- Initialize the routing tables of routers by filling them only with their direct neighborns
- Following the order of routers:
  - Send to each neighborn its DV
  - Update the nightborn routing table if DVe[A].cost + c(A, E) < RA[A].cost
  - Repeate until we finish the neighborns

**Count to infinity** is a problem concerning DV alorithm.

![https://i.imgur.com/Wec3VSy.png](https://i.imgur.com/Wec3VSy.png)

One solution to this problem is solved by setting a maximum number of hops bounded to 15. Another solution is **Split Horizon** where an extra link is added:

![https://i.imgur.com/XMUK0QE.png](https://i.imgur.com/XMUK0QE.png)

**Routing Information Protocol** (RIP) is a simple intradomain protocol implementing distance vector routing. The downsides of RIP are: slow convergence, limited network size; strengths: simple to implement, simple to manage.

## Link state vs Distance vector

Link state algorithms have knoledge of the whole network, Distance Vecor algorithms know only of the nighborns.

Message complexity:

- LS: with n nodes, E links, O(nE) msgssent
- DV: exchange between neighbors only, convergence time varies

Speed of convergence:

- LS: O(n^2) algorithm requires O(nE) msgs, may have oscillations
- DV: convergence time varies, may be routing loops, count-to-infinity problem

Robustness: what happens if router malfunctions?

- LS: node can advertise incorrect link cost, each node computes only its own table
- DV: node can advertise incorrect path cost, each node’s table used by others, **error propagate** thru network

## BGP

So far we studied how routing is performed within one AS. How about routing outside the AS, e.g., between different ISPs? This is done using **Border Gateway Protocol** using a technique called Inter-AS routing.

Border Gateway Protocol provides each AS:

- eBGP(exterior): obtain subnet reachability information from neighboring autonomous systems
- iBGP(interior): propagate reachability information to all AS-internal routers
- determine "good" routes to other networks based on reachability information and policy
- allows subnet to advertise its existence to the rest of the Internet: "I am here"

How it works the **BGP session**: two BGP routers (“peers”) exchange BGP messages over semi-permanent TCP connection advertising paths to different destination network prefixes (BGP is a “path vector” protocol).

BGP achieving policy problem, for example suppose an ISP only wants to route traffic to/from its customers (doesn't want to carry transit traffic between other ISPs).

Why are Intra-AS and Inter-AS routing different? Performance: intra-AS can focus on performance, inter-AS policy may dominate over performance.

![https://i.imgur.com/9ASOo7K.png](https://i.imgur.com/9ASOo7K.png)

## Data Link

Data-link layer has responsibility of transferring datagrams from one node to physically adjacent node over a link. In data-link layer error detection is used in low bit-error link (fiber, some twisted pair), it's used for high error rates links like wireless.

In data link layer the sending side encapsulates datagram in frame and adds error checking bits, and the receiving side looks for errors, extracts datagram and passes to upper layer at receiving side.

In **EDC** (Error Detection and Correction bits) the error detection not 100% reliable, protocol may miss some errors, but rarely, larger EDC field yields better detection and correction. One protcol is CRC.

**CRC** (Cyclic redundancy check) is used for detecting an n-bit data block of arbitrary length, it will detect any single error burst not longer than n bits, and the fraction of all longer error bursts that it will detect is (1 − 2^−n).

## Multiple access protocols

Two or more simultaneous transmissions by nodes: collision if node receives two or more signals at the same time. Multiple access protocol is a distributed algorithm that determines how nodes share channel, i.e., determine when node can transmit.

What it does is: when M nodes want to transmit at R rate, each can send at average rate R/M. This has the pro to be fully decentralized, so no special node to coordinate transmissions and no synchronization of clocks.

This has Three broad classes:

- **channel partitioning**: divide channel into smaller “pieces” and a frame is sent every n-frames
- **random access**: channel not divided, allow collisions and “recover” from collisions
- “taking turns”: nodes take turns, but nodes with more to send can take longer turns

## Channel partitioning

For **channel partitioning** there are different protocols.

One of them is **TDMA** (time division multiple access) protocol: each station gets fixed length slot (length = packet transmission time) in each round, unused slots go idle:

![https://i.imgur.com/s77qubO.png](https://i.imgur.com/s77qubO.png)

**FDMA** (frequency division multiple access): frequency division multiple access, each station assigned fixed frequency band, unused transmission time in frequency bands go idle:

![https://i.imgur.com/BS6kiYq.png](https://i.imgur.com/BS6kiYq.png)

## Random access protocols

Random access protocols work in this way: when node has packet to send transmit at full channel data rate R without a priori coordination among nodes, if two or more are transmitting there is a collision.

**Random access MAC** protocol specifies: how to detect collisions and how to recover from collisions. Some example of Random access MAC protocols are: slotted ALOHA, ALOHA, CSMA, CSMA/CD and CSMA/CA.

## Slotted ALOHA

In **Slotted ALOHA** all frames same size, time is divided into equal size slots (time to transmit 1 frame), nodes start to transmit only at slot beginning, nodes are synchronized, if 2 or more nodes transmit in slot, all nodes detect collision, in that case retransmit after n random frames.

Pros: single active node can continuously transmit at full rate of channel and it's highly decentralized: only slots in nodes need to be in sync. Cons: collisions, wasting slots, needs clock synchronization.

![https://i.imgur.com/AqgcGJy.png](https://i.imgur.com/AqgcGJy.png)

## ALOHA

The **Pure (unslotted) ALOHA** is simpler and doesn't require synchronization, When frame first arrives transmit immediately, Collision probability increases.

![https://i.imgur.com/L5KI9Uk.png](https://i.imgur.com/L5KI9Uk.png)

## CSMA

**CSMA** (carrier sense multiple access) works on listening before transmitting. Transmitting packages works in this way:

- **if channel is busy** then wait to become free
- **if channel is free**:
  - with probability p: trasmit frame
  - with probability 1-p: defer transmission by a random time much larger than the transmission time, after defer time, repeat procedure

So with 0-persistent transmit immediatly, with 1-persistent always transmit after delay.

One problem with CSMA is that there is a **vulnerable period**: if a station starts to transmit but the signal has not reached all stations, other stations might start transmitting. And another one is that of two nodes may not hear each other's transmission.

![https://i.imgur.com/dBGY6C7.png](https://i.imgur.com/dBGY6C7.png)

## CSMA/CD

**CSMA with collision detection** works that when transmitting a packet, the senders listen to the network and in case there is any problem. This is easy in wired LANs and difficult in wireless LANs.

Works in this way: If NIC senses channel idle, starts frame transmission, if NIC senses channel busy, waits until channel idle, then transmits, if NIC transmits entire frame without detecting another transmission, NIC is done with frame! If NIC detects another transmission while transmitting, aborts and sends jam signal

![https://i.imgur.com/btaluYF.png](https://i.imgur.com/btaluYF.png)

## CSMA/CA

**CSMA with collision avoidance** is used when it is not possible to detect collisions. CA means to behave in a p-persistent manner, with p being adapted to network conditions, p decreases at each retransmission attempt. Using CSMA 1-persistent is not convenient because collisions can't be detected.

## “Taking turns” MAC protocols

**Polling**: master node “invites” slave nodes to transmit in turn, typically used with “dumb” slave devices. The problems are: polling overhead, latency, single point of failure (master).

![https://i.imgur.com/08DDbfZ.png](https://i.imgur.com/08DDbfZ.png)

**Token passing**: control token passed from one node to next sequentially. Problems: token overhead, latency, single point of failure (token).

![https://i.imgur.com/edFAiiA.png](https://i.imgur.com/edFAiiA.png)

## Switch

The **switch** is a device, where each link is its own collision domain. Switches know where to send packets because they have something like a routing table. Switch learns which hosts can be reached through which interfaces when frame received, switch “learns” location of sender.

When frame received at switch: Record incoming link, MAC address of sending host, Index switch table using MAC destination address, If entry found for destination then: forward frame on interface indicated by entry, else flood (forward on all interfaces except arriving interface).

The same works with switches interconnected to other switches.

![https://i.imgur.com/5XlO88p.png](https://i.imgur.com/5XlO88p.png)

## Switch vs Router vs Hubs

Store-and-forward and Forwarding tables comparison.

- routers
  - network-layer devices (examine network-layer headers)
  - compute tables using routing algorithms, IP addresses
- switches
  - link-layer devices (examine link-layer headers)
  - learn forwarding table using flooding, learning, MAC addresses
- hubs
  - simply repeat signal
  - no forwarding table

**Collision domain** is a portion of the network in which, whenever two or more stations transmit simultaneously, a collision occurs.

**Broadcast domain** is a portion of the network that can be reached via a layer-2 broadcast

Orange = Broadcast domain, Blue = Collision domain:

![https://i.imgur.com/YJ3DW96.png](https://i.imgur.com/YJ3DW96.png)
