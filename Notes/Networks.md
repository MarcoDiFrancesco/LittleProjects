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

**Protocol stack** is a collection of protocols and of their relationships defining a logical and pysical communication architecture.

Every **layer** of a protocol stack is composed by 2 sub-systems, every **sub-system** is composed by **entities**.

![https://i.imgur.com/jDRKccf.png](https://i.imgur.com/jDRKccf.png)

Every layer provides services to the **upper layer** throgh a **Service Access Points**. A SAP is the "API" of the stack, in which layers communicate. Layer N+1 only knows that lower layers offer an N-service and what is below it, is a black box.

![https://i.imgur.com/RD39eed.png](https://i.imgur.com/RD39eed.png)

In a system with M layers:

- The **service data unit** (SDU) is the "packed" piece of data recived from the layer above
- The **protocol control information** (PCI) is the piece of data attached to the SDU containing the receiver and sender addresses
- The **protocol data unit** (PDU) is the result of SDU + PCI, and it is passed to the layer below

### Segmentation and reassembling

The PDU can be:

- **segmented** when the block is too large to be transported
- **assembled** when the blocks are too small to be transported, so they are bundled togeder
- **re-assembled** after the sagmented blocks have been received

## Internet protocols

ISO/OSI vs TCP/IP:

The **International Organization for Standardization** created the **Open System Interconnection** model (ISO/OSI), it is an abstract model.

The Internet protocol suite is the conceptual model and set of communication protocols used in the internet. It's known as TPC/IP because the of its fundamental protocols: **Transmission Control Protocol** (TCP) and **Internet Protocol** (IP).

![https://i.imgur.com/4nM12CK.png](https://i.imgur.com/4nM12CK.png)

![https://i.imgur.com/RAbVT6O.png](https://i.imgur.com/RAbVT6O.png)

ISO/OSI procols:

![ISO/OSI](https://i.imgur.com/c5rDXCK.png)

Layer 1: **Physical** is in the bottom of the model. It takes care of transmitting raw bits on the interface via electrical, electro-magnetic, light, sound ways signals. It defines encoding, voltages, modulations.

Layer 2: **Data link** (OSI) or **Link** (TCP/IP) makes the [multiplexing and demultiplexing](#multiplexing-and-demultiplexing) of layer 3 protocols, error discovery and recovery, medium access control (MAC sublayer). Some example protocols are: DSL, 802.11, Ethernet. Here packets are called frames.

Layer 3: **Network** (OSI) or **Internet** (TCP/IP) makes routing and forwarding, congestion control. It can make the routing in two ways: connection-less in which each packet is sent indipendently, and connection-oriented in which the route is establiched once, and used for all packets belonging to a specific host to host communication. Some example procols are: IP, ICMP. Here packets are called packets or datagrams.

Layer 4: **Trasport** makes the application [multiplexing and demultiplexing](#multiplexing-and-demultiplexing), performs [segmentation and reassembles](#segmentation-and-reassembling) data, error control, flow control, packet ordering. Some example protocols are: TCP, UDP. Here packets are called datagrams or segments.

Layer 5: **Session** Manages data exchange so this can be paused, restared and terinated. For example if a whatsapp call changes from wifi to cellular the layer manage not to disconnect.  

Layer 6: **Presentation** makes encryption, data rappresentation (encoding).  

Layer 7: **Application** provides to the applications the means to communicate and exchange data, e.g. FTP, SSH, POP3, IMAP, SMTP, HTTP, DNS, SSH .

## Structure of the internet

**ISP** (internet service provider) connects the end systems to internet. The ISPs are interconnected so that and two hosts can send packets to each other.
The ISPs can be devided in categories:

- **Tier-1** networks like AT&T connect distant networks, like networks located in different continents
- **Content provider** networks like Google, Microsoft run their (private) network to bring their services close to the end user
- **Regional** networks like Tim, Telecom, Vodafone are connected to one or more Tier-1 ISPs and internet exchange points (IXPs)
- **Access ISP** make the last mile communication

![ISP networks](https://i.imgur.com/cQf9Ke6.png)

## Network architectures

The **client-server** architecture makes the server always-on host, servers have permanent IP addresses, the clients do not communicate directly with each other.

The **P2P** architecture, like torrent, make the end systems communicate directly, the con of the P2P architenture is that the management of the network is complex.  
The communication client-server and P2P is done with **sockets** that works like doors for the communication. Each layer use sockets to communicate with the layer above and below.

![Socket management](https://i.imgur.com/EtdWsg7.png)

App-layer **protocols** like HTTP, SMTP allow types of messages to be exchanged with a specific semantic. Rules are specidied for each protocol. Protocols can be open like HTTP, SMTP or proprietary like Skype.

The **transport service** of an application can require some needs:

- **Data integrity** like a downloaded file requires 100% reliable data transfer
- **Timing** like phone call or gaming requires low latancy, if there is some data lost it's not that big problem
- **Throughput** like video streaming requires large throughput, losing data in this case is not a big ploblem
- **Security** like mails require enctyption and data integrity

There are two main internet transport protocol services TCP and UDP.

### TCP architecture

- makes the **connection reliable**
- manages flow and **congestion control** (making the connection slower in case the network is full)
- it's **connection-oriented**
- does **not** provide
  - timing
  - minimum throghput
  - security

### UDP architecture

- establish an **unreliable data tranfer** service
- does **not** provide
  - reliability
  - flow control
  - congestion control
  - timing
  - throughput guarantee
  - security
  - connection setup

The UDP protocol exists beacause it's not possible to use just IP protocol bacause it doesn't use any port.

TCP and UDP **can be encrypted**. SSL provides encypted TCP connection, **data integrity** and **end-point authetication**.

### HTTP

The **web** connetion like HTTP are web pages consisting of objects like HTML files, JPEG images, audio files. The connection in HTTP make a request and receive a response. This connection is manages by the browser. The connection over TCP is initiated creating a socket in the 80 port and communicates over HTTP messages and then it closes the connection.

In HTTP the connection is **state-less**, it does not mantain any information about the previous client requests.

The HTTP can be **persistent** ot **non-persistent**: it's non-persistent when it doens't mantain the TCP connection, so when openening a new request every time it asks for a file. It's persistent when multple objects can be sent over a single TCP connection.

**HTTP** handles two types of messages: requests and responses. The request message is encoded in ASCII so it's human readable. Some of the important lines of a **GET request** are:

- the host
- user-agent (the browser name)
- the acceped language
- acceped encoding
- acceped charset
- acceped time
- connection (persistent or non-pesistent)

The HTTP requests can make requests using GET and POST mothods.  

### HTTP GET Request

``` HTTP
GET /index.html HTTP/1.1\r\n
Host: www-net.cs.umass.edu\r\n
User-Agent: Firefox/3.6.10\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us,en;q=0.5\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8;q=0.7\r\n
Keep-Alive: 115\r\n
Connection: keep-alive\r\n
\r\n
```

### HTTP Response

``` HTTP
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
- HEAD asks server to leave requested object out of response
- PUT uploads file in entity body to path specific in URL field
- DELETE which deletes file specified in the URL field

Some of the HTTPS response status codes are:

- 200 OK
- 301 Moved permanently
- 400 Bad request
- 404 Not fould
- 505 HTTP version not supported

### Cookies

The are 4 main types of **Cookies**: cookies header line of HTTP response meassage (Susan always access internet from PC), cookie header line in next HTTP request message (she visits specific e-commerce site fo the first time), cookies file kept on a user's host manages by the browser (to give unique ID in a login so that in refres the browser doesn't log out) and back-end database at Web site (website tracks the user shopping list).

![Cookies](https://i.imgur.com/DZ42h5b.png)

### Proxy server

**Proxy servers** are used to cache a certain web page. For example if a user in the university (using the university's proxy server) request a static page from a web server the proxy server saves it, so in case another user request it, the proxy server won't reach it another time.  
Proxy server acts as both client and server, in the server side a preprocessed page can be given to a user if he requests it in short period of times.

In HTTP there is also the **conditional GET**, it doesn't sent object if cache has up-to-date cached version.

![Conditional GET](https://i.imgur.com/f2VcYzK.png)

### Electionic mail

**SMTP** uses TCP to transer email messages through port 25, it uses persistent connections.

**IMAP** is Internet Mail Access Protocol stores the email in the mail servers (for example gmail).

![IMAP](https://i.imgur.com/dtiVb7r.png)

**POP3** is stateless across sessions and by default it "downloads and delete" emails.

### DNS

DNS makes the translation from hostname to IP address. A problem of DNS is that has a single point of failure so does not scale.

![DNS](https://i.imgur.com/ScGAE4J.png)

The **DNS root name** servers are 13 in all the world and return the mapping to local name servers.

The **Top-Level Domain** (TLD) servers are responsible for com, org, net, edu, aero, jobs, museums, and all top-level country domains, e.g.: uk, fr, ca, jp.

The **local DNS** is owned by the ISP and it's the first DNS contacted by a user.

The DNS can cache the recods with a TTL so the TLD are not so often visited.

### Lightweight directory access protocol (LDAP)

LDAP is used to store DNS recors. The LDAP can be query with a directory information base (DIB) and can contain wildcards.

![LDAP](https://i.imgur.com/aqrgh7L.png)

### P2P applications

The P2P architecture works with communication between peers. Known examples are Skype and BitTorrent.

BitTorrent protocol devides into 256Kb the files that want to transmit.

### CDN

The **DASH** (Dynamic, Adaptive Streaming over HTTP) streams multimedia so that the server the effort is divided in multiple CNSs.

The server devides video file into multiple chunks, is encoded at different rates, and creates the manifest file contains URLs for the different chunks. The clint checks the bandwidht and consult th emanifest to get the more appropiate chunk. The client can check for the closest CDN and the Resolution wanted.

## Transport Layer Services

The transport layer services are used to proovide a logical communication between processes running on different hosts.

### Multiplexing and demultiplexing

**Multiplexing**: gathering data from multiple application processes of sender, enveloping that data with header and sending them as a whole to the intended receiver.

**Demultiplexig**: delivering received segments at receiver side to the correct app layer processes

Multiplexing means that the sender handle data from multiple sockets and add the trasport header and demultiplexing at receiver means to use header info to deliver receive regments to correct socket.

Each datagram uses IP addresses and port numbers to direct the segment to the appropriate socket.

The sockets are 16 bit integers with values up to 65535.

![demultiplexing](https://i.imgur.com/mdIMnc7.png)

### User datagram protocol (UDP)

Is a **best effort service** and secgments may be lost or delivered out of order, there is not reliability on when a datagram is transfered.

UDP makes **checksums** and attack them to the headers to detect errors.

### ARQ

**Automatic Repeat reQuest** (ARQ) is a class of protocols that deals with packet loss, and it's made to notify the transmitter of the reception using acknoledgments.

Some ARQ protocol examples are:

- Stop and wait
- Go-back-N
- Selective Repeat
- TCP
- WiFi-s MAC protocol

### Stop and wait

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

![Stop and wait](https://i.imgur.com/sJREwAr.png)

Example Stop and wait

![Stop and wait example](https://i.imgur.com/QWbfBTE.png)

### Pipelined protocols

Pipelining increases utilization of the bandwidth.

The **transmission windows** (`Wt`) is the number of PDUs that the transmitter is allowed to transmit without receiving an ACK.

`|Wt|` indicates the size of the window.

The receive windows (`Wr`) is the number of PDUs that the receiver is capable to accept and memorize.

In the transmission window Wt the **low pointer** (`Wlow`) is the first packet.
In the transmission window Wt the **up pointer** (`Wup`) is the last packet.

![transmission and receive windows](https://i.imgur.com/442DBJ5.png)

### Acknoledgements

There are different types of ACKs:

- **individual ACK** that indicates the correct reception of a specific packet `ACK(n)`
- **cumulative ack** indicates the correct reception of ACKs up to a certain packet. `ACK(n)` means I received everythink up to packet n (not included)
- **neative ACK** (NACK) request retrasmission of a single packet `NACK(n)`
- **piggybacking** means inserting ACK data into a packet

Pipelined protocols examples are Go-back-N and Selective repeat.

### Go-back-N

![Go-back-N](https://i.imgur.com/9qs1Jsj.png)

### Selective repeat

![selective repeat](https://i.imgur.com/Ea0v9Gl.png)

The **main difference** between the two protocols is that the first one, if it gets an ack that is not exactly in order, it rejects everything else except the expected packet, and in selective repeat the packets that are not exactly in order, they get accepted anyway (if the receiver window is big enough).

### TCP

Transmission Control Protocol (TCP) is:

- **point-to-point** because there is one sender and one receiver
- **reliable** because the byte are ordered
- congestion and flow control **set windows size**
- **windows sizes** are dynamic
- **cumulative** ACKs
- **clogging the network** is avoided thanks to congestion control
- **bi-directional** data flow
- sender will **not overwhelm** receiver

### TCP structure

![TCP structure](https://i.imgur.com/lPEgGJq.png)

- RWND is a 16-bit field with max value 65536 bytes

Maximum Transfer Unit
Default MTU = 1500 bytes

Maximum Segment Size
Default MSS = 1500 bytes - 40 bytes (MSS - header)

Retrasmission time out (RTO)

### Connection setup

![Connection setup](https://i.imgur.com/LaBzWnQ.png)

### Finish procedure

![FIN procedure](https://i.imgur.com/PtPE3Bi.png)

### Round trip time

Smothed RTT: **SRTT = (1 -alpha)\*SRTT + alpha\*RTT**
Typical value: alpha = 0.125

![SRTT](https://i.imgur.com/CK4KZ2v.png)

CWND (Congestion) is **upper bounded** by RWND (Receiver)
|WT| = min(CWND, RWND) (or min(CWND, |Wr|))

### Slow start

For every ACK received increase CWND by one MSS:

- start
  - CWND = 1 MSS
  - SSTHRESH = RWND (or RWND/2 depending on the implementation)
- on valid ACK
  - CWND = CWND + 1 MSS
  - move Wlow according to ACK
  - if CWND >= SSTHRESH -> switch to Congestuib Avoidance
- on RTO timeout
  - SSTHRESH = max(CWND/2, 2)
  - RTO = RTO * 2
  - CWND = 1
  - retransmit the missing segment

Example:

- receive ACK after RTT -> CWND = 2 MSS
- receive 2 ACKs after RTT -> CWND = 4 MSS

![Slow start](https://i.imgur.com/P4nGi3k.png)

### Congestion avoidance

For every valid ACK received:

- CWND = CWND + MSS * MSS / CWND
- move Wlow according to ACK

On RTO timeout

- switch to slow start
- SSTHRESH = max(CWIND/2,2)
- RTO = RTO * 2
- CWND = 1
- retransmit missing segment

Basically for every RTT in which CWND ACKs are received increase CWND by MSS

![Congestion avoidance](https://i.imgur.com/L14zVT8.png)

### Fast retransmit and fast recovery

Fast recovery idea is: if the network is working try to contunue transmitting.

On 3rd duplicated ack

- SSTRESH = CWND / 2
- CWND = SSTRESH + 3 MSS
  - if CWND allows, send new segments
- do not move Wlow

On additional duplicated ACK

- CWND = CWND + 1 MSS
- if CWND allows send new segments
- do not move Wlow

On new ACK

- CWND = SSTHRESH
- swith to congestion avoidance
- move Wlow according to ACK

On partial ACK

- retransmitting first anacknowleged segment
- SWND = CWND - amount of unacknoledged data +1
- move Wlow according to ACK

![Fast recovery example](https://i.imgur.com/8bD100W.png)

### Slow start only vs Fast retransmit and recovery

![Slow start only](https://i.imgur.com/d8HFH16.png)

![Fast retransmit and recovery](https://i.imgur.com/ZCEpQ81.png)
