# Machine learning

The **difference between classical programing and machine learning** is that instead of writing down every little detail into the program and request it to compute it all, you set up an automated system to test the effectiveness of weight assignment in terms of actial performance, and provide a mechanism for altering the weight assignment so as to maximize the performance.

The **model** is the thing that is used in machine learning to keep all weights.

The **stochastic gradient decent** is general thing that updates the weights inside a neural network.

The **loss** is a function that computes how good the prediction of a neural network are so then it's possible to other functions to update the weights.

Deep learning is a branch of machine learning. Deep leaning is the technique used to perform machine learning.

In the neural netowork there are 3 types of layer:

- input layer (one per nerwork)
- output layer (one per network)
- hidden layer (all the layers in the middle)

![artificial neural network](https://i.imgur.com/37xUpam.png)

The thing between the nodes is called **connection**. Each connection is assigned with a value between 0 and 1.

![connection](https://i.imgur.com/HkxdX6e.png)

The output correspond to the number of classification we want. If we want 3 classifications (like cats, dogs and bears) we will have 3 nodes.

The **optimazer** in a neural network the algorithm that calculate the values to optimize the ouput. The objective of an optimizer is to minimize the loss function. A famous algorithm is SGD.

An example of what the optimzer is trying to do is calculating the output if an image is a dog or a cat. In the case the image is a cat and the algorithm predicted that it was a cat, then the algorithm will adjust to minimize the error.

The leaning rate is a value usually between 0.01 and 0.0001 that is used to update the value in the node in this way:

`(d(loss)/d(weight))*LearningRate`

Raising the leaning rate means that we could **overshoot** and miss the minimum of the minimize loss function.  
Lower the leaning rate means learning slower.  
This number is just guessed.

The error is calculated as `expected_value-real_value`.

A loss function is an avarage of the errors to compute a loss number to understand how well an algorithm is performing.  
A common loss function is MSE (mean sqared error).

The training sets are:

- training sets: used to train the model
- validation sets: used to validate the model (not while learning) to adjast the values
- test sets: is an unlabled set where we try the model

**Overfitting** is the problem that comes when the model is able to perform really well in training data, but when going in validation data it performs really bad.

Overfitting can be fixed using a proper validation set.

![https://i.imgur.com/uBdSS2e.png](https://i.imgur.com/uBdSS2e.png)

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
