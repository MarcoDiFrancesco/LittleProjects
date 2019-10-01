# Networks
The **protocols** are used make a logical and physical connection between architectures. The protocols are devided in layers, so complex systems can be splitted in more simple system's pieces so it makes the update easier.  
The layers are connected using **service access points** (SAP). These are the "API" of the stack, in which layers communicate. Layer N+1 only knows that lower layers offer an N-service and what is below it, is a black box.

![N+1 service](https://i.imgur.com/FxKEVwd.png)

The **service data units** (SDU) in a system is the "packed" piece of data recived from the layer above.
The **protocolo control information** (PCI or M-PCI when talking about the M layer) is the piece of data attached to the SDU.
SDU + PCI creates the **protocol data unit** (PDU) that will be passed to the layer below.

![Communication between layers](https://i.imgur.com/xvvGyR7.png)

The data units can be:
- **segmented** when the block is too large to be transported
- **assembled** when the blocks are too small to be transported, so they are bundled togeder
- **re-assembled** after the sagmented blocks have been received

### ISO/OSI

![ISO/OSI](https://i.imgur.com/c5rDXCK.png)

Layer 1: **Physical** is in the bottom of the model. It takes care of transmitting raw bits on the interface via electrical, electro-magnetic, light, sound ways. It defines encoding, voltages, modulations.  
Layer 2: **Link** is makes the multiplexing (gathering data togeder, putting a header and sending them as a big packet) and demultiplexing (deviding packets, removing the header and sending to the layer 3), it makes the error discovery and recovery, it makes the medium access control (MAC sublayer).  
Layer 3: **Network** make routing, forwarding and congestion control. It can make the routing in two ways: connection-less in which each packet is sent indipendently, and connection-oriented in which the route is establiched once and used for all packets belonging to a specific host to host communication.  
Layer 4: **Trasport** performs segmentation and reassempling data, error control, flow control, packet ordering.  
Layer 5: **Session** Manages data exchange so this can be paused, restared and terinated.  
Layer 6: **Presentation** makes encryption, encoding and data rappresentation.  
Layer 7: **Application** provides to the applications the means to communicate and exchange data, e.g. FTP, SSH, POP3, IMAP, SMTP, HTTP.

![Communication between hosts example](https://i.imgur.com/kCC1wbt.png)

### Structure of the internet

**ISP** (internet service provider) connects the end systems to internet. The ISPs are interconnected so that and two hosts can send packets to each other.
The ISPs can be devided in categories:
- **Tier-1** networks like AT&T connect distant networks, like networks located in different continents
- **Content provider** networks like Google, Microsoft run their (private) network to bring their services close to the end user
- **Regional** networks like Tim, Telecom, Vodafone are connected to one or more Tier-1 ISPs and internet exchange points (IXPs)
- **Access ISP** make the last mile communication

![ISP networks](https://i.imgur.com/cQf9Ke6.png)

### Network architectures
The **client-server** architecture makes the server always-on host, servers have permanent IP addresses, the clients do not communicate directly with each other.  
The **P2P** architecture, like torrent, make the end systems communicate directly but the management of the network is complex.  
The communication client-server and P2P is done with **sockets** that works like doors for the communication.

![Socket management](https://i.imgur.com/EtdWsg7.png)

App-layer **protocols** like HTTP, SMTP allow types of messages to be exchanged with a specific semantic. Rules are specidied for each protocol. Protocols can be open like HTTP, SMTP or proprietary like Skype.  
The **transport service** of an application can require some needs:
- **Data integrity** like a downloaded file requires 100% reliable data transfer
- **Timing** like phone call or gaming requires low latancy, if there is some data lost it's not that big problem
- **Throughput** like video streaming require large throughput and losing data trading off some data lost
- **Security** like mails require enctyption and data integrity
