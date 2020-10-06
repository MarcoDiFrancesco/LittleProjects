# Logic

Logic course 3rd semester Unitn.

## Conceptual model

A **conceptual model** is a meaningful representation of the world, described in a certain **language**.  
**Conceptual modeling** is the activity of building conceptual models.  

## Mental model

**World** is what we perceive.  
**Mental model** is a representation of the world composted in 4 consistuents.  
**Semantic gap** is the difference between the world and the mental model.  

**Language** is the alphabet and the syntax used to describe the world.  
**Theory** is formed of sentences describing what ***is true*** in the world aka facts.  
**Domain** is formed of "images and pictures" which represent atomic elements used to describe what we see.  
**Model** is formed of "images and pictures" which represent the sets of facts (scenes) that we have seen (and are true).

Menatal model:

![https://i.imgur.com/J1DJm16.png](https://i.imgur.com/J1DJm16.png)

Mental model rappresentation:

![https://i.imgur.com/EjpqXv8.png](https://i.imgur.com/EjpqXv8.png)

Logical model

**World** *same*.  
**Logical model** *same*.  
**Semantic gap** *same*.

**Language** *same*.  
**Theory** *same*.  
**Domain** are *sets of elements* which represent atomic elements used to describe what we see.  
**Model** are *sets of elements* which represent the sets of facts (scenes) that we have seen (and are true).

**Interpretation** is a function which associates each and any element of the language to one and only one element of the domain.  
**Entailment** (aka truth-relation or satisfiability) is a relation which associates what is true in a model with a subset of the sentence of the language.  
Note that a sentence can be an element in a theory if and only if its interpretation is true in the model.

Logical model:

![https://i.imgur.com/MBvm6Hf.png](https://i.imgur.com/MBvm6Hf.png)

Logical model representation:

![https://i.imgur.com/ijkWOAX.png](https://i.imgur.com/ijkWOAX.png)

### Language

The **language** is a set of symbols (usually finite) and formation rules to compose "correct sentences". For example:

- Monkey and GetBanana are symbols (atomic sentences)
- Monkey ∧ GetBanana is a sentence (rule: A ∧ B)

The **syntax** is the way a language is written, it is determined by a set of rules saying how to construct the expressions of the language from the set of atomic tokens (e.g. terms, characters, symbols, letter of the alphabet)  
The **semantics** is the way a language is interpreted, it determines the meaning of the syntactic constructors.

The **formal syntax** is a finite or infinite alphabet used for building phrases with rules construction.  
The **formal semantics** is the relationship between syntactic constructors in a language and the elements of a universe of meanings with a mathematical function **Language → Domain**.  

### Logic components

A **logic** has three fundamental components:

- A **formal language** (L) that defines what can correctly be said
- An **interpretation function** (I) that defines how the atomic elements of the language are being interpreted in the intended domain and model
- An **entailment relation** (⊨) used to define two relations: **satifiability** that is when a formula is true, and **logical consequence** that is when the truth of a formula follows from the truth of a set of formulas

Given L, I and ⊨ a logic allows to define two components: **theory** that is a set of sentences in L which are assumed true in the intended model, and **model** that is the set of facts expressed in the language describing the mental model in an agreement with the theory and the interpretation function.

---

**Interpretation function** assigns a true or false value to each variable.  
An Interpretation function is called a **model** of a function φ if its assignments make the value of the function true. In symbols: I |= φ.  
