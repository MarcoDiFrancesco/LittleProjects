# Machine learning

The **difference between classical programing and machine learning** is that instead of writing down every little detail into the program and request it to compute it all, you set up an automated system to test the effectiveness of weight assignment in terms of actial performance, and provide a mechanism for altering the weight assignment so as to maximize the performance.

## Deep learning

Deep learning is a branch of machine learning. Deep leaning is the technique used to perform machine learning.

The **model** is the thing that is used in machine learning to keep all weights. There are 2 main types of model: **classification** if is trying to predict a category like a cat or a dog, and **regressing** if I'm trying to guess one or more numeric quantities.

In neural netoworks there are 3 types of layer (vertical collection of nodes):

- input layer (one per nerwork)
- output layer (one per network)
- hidden layer (all the layers in the middle)

The thing between the nodes is called **connection**. Each connection is assigned with a weight between 0 and 1.

![connection](https://i.imgur.com/HkxdX6e.png)

The output corresponds to the number of classification we want. If we want 3 classifications (like cats, dogs and bears) we will have 3 nodes.

The **loss function** is a function that computes how good the prediction of a neural network are so then it's possible to other functions to update the weights. A common loss function is MSE (mean sqared error). There can be 2 losses function: training loss and validation loss, depending on the types of set you are looking at.

The **optimazer** in a neural network the algorithm that calculate the values to optimize the ouput. The objective of an optimizer is to minimize the loss function. A famous algorithm is SGD. An example of what the optimzer is trying to do is calculating the output if an image is a dog or a cat. In the case the image is a cat and the algorithm predicted that it was a cat, then the algorithm will adjust the weights to minimize the error.

The **stochastic gradient decent** is general thing that updates the weights inside a neural network.

The **leaning rate** is a value usually between 0.01 and 0.0001 that is used to update the value in the node in this way: `(d(loss)/d(weight))*LearningRate`. Raising the leaning rate means that we could **overshoot** and miss the minimum of the minimize loss function. Lower the leaning rate means learning slower. This number is just guessed.

**Overfitting** is the problem that comes when the model is able to perform really well in training data, but when going in validation data it performs really bad. Overfitting can be fixed using a proper validation set.

The training sets are of 3 types:

- **training sets**: used to train the model
- **validation sets**: used to validate the model (not while learning) to adjast the values
- **test sets**: is an unlabled set where we try the model

**Transfer learning** is a technique in which a pre-trained model is used to start training instead of sarting from scratch. This is really helpful if a dataset has already learned some features, and you want it to look at a feature that is a mix of other features, for example you want it to recognise a book, when it already recognize text and edges.

## Convolutional Neural Network

A Convolutional Neural Network (or CNN) is used to detect patterns in an image.

A CNN is made of convolutional layers and non-convolutional layers. A convolutional layer has filters that can be specified to detect the patterns. A pattern in an image can be a circle, or an edge, or a particular shape. If the pattern we want to detect is an edge, then it's called an edge detector.

Convolving in a CNN means this:

![CNN](https://i.imgur.com/Z2biR1U.png)

With the result in the left then we can understand something, like the edges in this example:

![edge detector example](https://i.imgur.com/SfNZ4Z1.png)

With this result we can then detect more advance things, like in this example:

![edge example](https://i.imgur.com/liBn1e1.png)

**Dilated convolutional neural network** is a technique in combo with CNN with the differnce that the kernel pixels is not one after the other, but rather there is distance between the 2:

![https://i.imgur.com/lAUdDiR.png](https://i.imgur.com/lAUdDiR.png)
