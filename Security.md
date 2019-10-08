# Security
**Information security** is the practise of preventing unauthorized access, use, disclosure, disruption, modification, recording or destruction od information.  
**Computer security** is the practise of protecting computer systems and information from theft, and unauthorized use. This practise include protecting hardware (with locks, dors etc.) and protecting software.  
**Network security** is the practise of taking physical and software preventative measures to protect the networking infrastructure from unauthorized access, malfunction, modification, destruction etc. creating a secure platform for computers, users and programs to perform their permitted functions.

![Security system](https://i.imgur.com/uzkMHlH.png)

**Cyber security** is the ability to protect and defend the use of cyberspace (a global domain consisting of interdependent network of information systems infrastructures, including the internet, embedded processors, telecommunications networks ecc.) from cyber attacks (an attack targeting an organization's use of cyberspace for the purpose of destroying, disrupting, disabling or controlling a computer infrastructure).  
**Cyber security readiness** is the ability to have critical information and tools rapidly available and in place in order to identify vulnerabilities, combat threats, deter attacks and remediate risks. The cyber security readiness improves security posture and allows the organization to remain complaint with the policy, regulations and laws.

## CIA triad
**Confidentiality** is the property that sensitive information is not discloses to unauthorized entities, preserving other entities accessing and disclose information, preserving personal privacy and proprietary information.  
**Integrity** is the property that sensitive data has not been modified or deleted in an untothorized and undetected manner. Authenticity is the property of being genuine and being able to be verified and trusted. Non-repudiation (auditability) is the protection against an individual dalsely denying having performed a particular action, this provides the capability to determine whether a given individual took a particular action such as creating information, sending a message, approving information and receving a message.  
**Availability** is a security goal that generates the requirement for protection against intentional or accidental attempts to perform unathorized deletion of data or otherwise cause a denial of service.  

## Security vs other propreties
**Reliability** addresses the consequences of accidental errors.  
**Safety** mesures the absence of catastrophic influences on the enviroment in a particular human life.  
**Dependability** is the property of a computer system such that reliance can be placed on the service it delivers.

**Vulnerabilities** is a weakness in a information system that could be exploited or triggered by a threat souce.  
**Threat** is a circumstance or event with the potential to impact organizational operations or individuals through unauthorized access, destruction, modification of information or denial of service.  
**List of threats**
- Breaking into a computer and impersonate someone I trust
- DOS attacks
- Worm is a self-replicating program that dies bit require user action to activate
- Stealing information from a computer or from communication
- Using a machine to attack others throgh emails, worms, dos attacks, spam and phishing
- Interfering with physical world: IoT, smart vehicles, power system, traffic control
**Risk** is the probability that a particular security threat will exploit a system vulnerability

![Risk matrix](https://i.imgur.com/Ikvc01f.png)

Security **Policy** is a set of rules and requirements established by an organization that governs the acceptable use of its information and services and the level and means for protecting the confidentiality, integrity and availability of its information. An example of policy is: the company's visitors must be escorted by an autorized emplyee and he must restrict them to appropriate areas. Another example is: Employees need to use a secure password on all systems and these credentials must be unique.  
Security **Mechianism** is a device or function designed to provide one or more security services usually rated in therms of strenght of service and assurance of the disign. An example is authentication: verifying the identity o user, process or device often as a prerequisite to allowinf access to resource in an information system. Another example is authorization that grants or denies access rights to a user, program or process.  
Security **Service** is the capability that supports one or more of the security requirements, for example key management, access control and authentication.

# Authentication
The **user athentication** is the process of verifying a claimed user identity.  
Authentication threats:
- Spoofing: attacker starts a program that presents a fake login screen and leaves the compter
- Phishing: attacker impersonates the system to trick a user into releasing the password to the attacker

## Protecting the password file
It's possible to protect password with 1-way functions aka hash functions. Given a certain password it's easy to compute the hash but not in the other way.  
Some hash functions:
- **MD4** is computationally feasible
- **MD5** has been broken
- **SHA-1** collision attacks reported
- **SHA-256** it's secure for now

**Salting** is a technique used to store password where in the (random) password is appended to a string and the password is hashed with that string.

**Single sign on (SSO)** is allows users to access multiple apps throgh a single authentication act. Good factors are usability, because only one password needs to be rememberd, security because the tokens needs to be complex, usability because you can get shared sessions. The cons is the security, because only one password need to be compromised.

![Assurance levels](https://i.imgur.com/AIUbfyg.png)

**Contextual authentication** is where the context around the user's login are considered and assessed (valutate) to then decide whether the person is who the say they are, is there's a chance they are not, then an appropriate action is taken. For example if I'm logging in a new computer in a place where I've never been, more steps in my authentication needs to be required and a notification should be sent to me.

### Cryptography
**Cryptograpy** is the science and study of secret writing.  
**Cryptoanalysis** is the science and study of methods of breaking ciphers.  
**Cryptography** cryptography and cryptoanalysis.  

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
A encryption scheme is secure if the cost of breaking the cipher exceeds the value of the encrypted information and the time required to break it exceeds the useful lifetime of the information. It's difficult to estimate the amount of effort required to cryptoanalyze cipthertext successfully.  

The essence of cryptograpy is to use a public algorithm and a private key.  
There are two types of tranformation in encryption: the **substitution** in which each element in the plaintext is mapped into another element, and the **trasposition** in which the elements in the plaintext are rearranged.  
The **Caesar cipher** is the algorithm in using substitution that shifts s fixed number of letter of the alphabet. There are 2 ways to break it: the brute force attack trying all the 25 possibilities or trying to see the distribution of the letters (vocals and consonants) inside the text.  

### Modern encryption
In the modern era new encryption techniques entered: stream encryption, block encryption and public-key encryption.  
**Symmetric key** cryptography use the same key to crypt and decrypt: `D(k,E(k,p))=p`.

![Symmetric key](https://i.imgur.com/WbNRmM2.png)

Types of symmetric key crypto:
**Stream ciphers** encrypt sequences of short data blocks under a changing key system, security relies on design on the key stream generator and typical block length is 1 bit/byte.  
**Block ciphers** encrypt sequences of long data blocks without changing the key, it has a typical length of 64/128/256/512 bits. A block cipher breaks the message in successive blocks M1, M2, M3, ..., Mn and enciphers each Mi with the same key k. DES (data encryption standard) and AES (advanced encryption standard) are well-known examples of block cipher systems.  

**DES** employ a 56-bit key that operates on 64-but blocks, is a deterministic algorithm operating on a block cipher. DES has 16 rounds. DES has been cracked in 1998 with a large number of Deep-Crack chip, taking less than 3 days to find a 56-bit by searching a total of 17,902,806,669,197,312 keys, calculating an average of 88,000,000,000 keys per second.

**AES** uses keys of 128, 192 and 256 bits.

**Public key cryptograpy** uses two different keys: a public key and a private key.

![Asymmetric key](https://i.imgur.com/yEojFdE.png)

The basic idea behind the PKC (Public key cryptograpy) is that a user has the public key that uses to encrypt a message and another user has a private key that uses to decrypt the message.  
The private and public key encryption can also be used for signatures offering the propreties:
- **Authentication** because the digital signature says a message is created by a known sender
- **Non-repudiation** because the sender cannot deny having sent the message
- **Integrity** beacuse message was not altered while transiting

The **RSA** (Rivest, Shamir, Adleman) uses a PKC algorithm for key exchange, digital signature and key encryption of small blocks of data. RSA uses a variable size encryption block and a variable size key. Key-pair is deliverd from a very large number, n, that is the product of two prime numvers chosen according to special rules:
- Primes may be 100 or more digits in lenght
- An attacker cannot determine the prime factors of n from this information alone and this is what makes the RSA algorithm so secure
- If a large number is created from two prime factors that are roughly the same size there is no known factorization algorithm that will solve the problem in a seasonable amount of time

A recent **vulnerability of RSA** has been discovered beacuse chips inside identity cards, programmable smartcards, authentication tokens ecc. were using common software libraries in which was possible to compute the private key of a 1024 and 2048 key lenght. This was possible due to a algorithmic vulnerability characterized by a specific structure of the generated RSA prime numbers. So it was possible to crack a 1024 bits key with $76 and 2048 bits for $40.000.

Another algorithm is **DH** (Diffie-Hellman) used for secret-key key exchange only, not authentication or digital signatures. DH uses the principle that the operation `x -> g^x(mod p)` is easy to compute but difficult to reverse.

![DH algorithm key](https://i.imgur.com/bbBTT5l.png)

### How DH works

![DH overview](https://i.imgur.com/535jhl7.png)

A known **vulnerability of DH** is the middle-in-the-man (MITH) attack

![DH MITM attack](https://i.imgur.com/comKAtO.png)

