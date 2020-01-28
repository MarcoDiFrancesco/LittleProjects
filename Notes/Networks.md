# Networks

## Architecture

ISO/OSI is an abstract model
TCP/IP is the architecture used in the internet

The **protocols** are used make a logical and physical connection between architectures. The protocols are devided in layers, so complex systems can be splitted in more simple system's pieces so it makes the update easier.  
The layers are connected using **service access points** (SAP). These are the "API" of the stack, in which layers communicate. Layer N+1 only knows that lower layers offer an N-service and what is below it, is a black box.

![N+1 service](https://i.imgur.com/FxKEVwd.png)

- The **service data units** (SDU) in a system is the "packed" piece of data recived from the layer above.  
- The **protocol control information** (PCI or M-PCI when talking about the M layer) is the piece of data attached to the SDU.  
- The **protocol data unit** (PDU) is crated by SDU + PCI, and it is passed to the layer below.

![PDI and PCI](https://i.imgur.com/PUFMoZg.png)

The PDU can be:

- **segmented** when the block is too large to be transported
- **assembled** when the blocks are too small to be transported, so they are bundled togeder
- **re-assembled** after the sagmented blocks have been received

### ISO/OSI

![ISO/OSI](https://i.imgur.com/c5rDXCK.png)

Layer 1: **Physical** is in the bottom of the model. It takes care of transmitting raw bits on the interface via electrical, electro-magnetic, light, sound ways. It defines encoding, voltages, modulations.

Layer 2: **Link** is makes the multiplexing (gathering data togeder, putting a header and sending them as a big packet) and demultiplexing (deviding packets, removing the header and sending to the layer 3), it makes the error discovery and recovery, it makes the medium access control (MAC sublayer).

Layer 3: **Network** make routing, forwarding and congestion control. It can make the routing in two ways: connection-less in which each packet is sent indipendently, and connection-oriented in which the route is establiched once and used for all packets belonging to a specific host to host communication.

Layer 4: **Trasport** performs segmentation and reassempling data, error control, flow control, packet ordering.  

Layer 5: **Session** Manages data exchange so this can be paused, restared and terinated. For example if a whatsapp call changes from wifi to cellular the layer manage not to disconnect.  

Layer 6: **Presentation** makes encryption, encoding and data rappresentation.  

Layer 7: **Application** provides to the applications the means to communicate and exchange data, e.g. FTP, SSH, POP3, IMAP, SMTP, HTTP.

### Structure of the internet

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

### TCP

- makes the **connection reliable**
- manages flow and **congestion control** (making the connection slower in case the network is full)
- it's **connection-oriented**
- does **not** provide
  - timing
  - minimum throghput
  - security

### UDP

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
