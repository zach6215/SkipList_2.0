# SkipList_2.0
Skip list example: Log base 2

A skip list is a linked list where each node has a "tower". The tower is represented by a vector of node pointers.
Each pointer points to the next node with a tower that is at least as high as the pointers height. The towers' heights
are generated based on a "coin flip".

  |   -------------------------------->   |
  |   ------------>   |   ------------>   |     <--TOWERS
 _|_  -----___---->  _|_  -->  _|_  -->  _|_
|   | --> |   | --> |   | --> |   | --> |   |   <--NODES
