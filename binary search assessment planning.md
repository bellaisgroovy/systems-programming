#ae1 #part-1 

Delete (node, elem)
1. find node with value element
2. if found node is a leaf, remove pointer in parent
	1. if no left and no right
	2. delete reference in parent of found node
	3. free found node
	4. end if
3. if has two children, find largest value in left subtree and swap it in
	1. if left and right
	2. get largest in left subtree
	3. set value of node to be deleted to left max's value
	4. deal with left max's child
		1. if left max has a left child
		2. left max parent right = left max left child
		3. left max left child parent = left max parent
		4. free left max
		5. end if
	5. free left max
4. if has one child make connection between child and parent, then free
	1. if left and not right
	2. left child parent = parent
	3. ref in parent = left child
	4. end if
	5. if right and not left
	6. right child parent = parent
	7. ref in parent = right child
	8. end if