CFLAG := -Wno-implicit-function-declaration

tree: final
BT: final2

final: c_utils.o BinaryTree.o
	echo "building final"
	gcc -o final BinaryTree.o c_utils.o

final2: c_utils.o BST.o
	echo "building final2"
	gcc -o final2 BST.o c_utils.o

c_utils.o: c_utils.c
	echo "building utils"
	gcc $(CFLAG) -c c_utils.c

BinaryTree.o: BinaryTree.c
	echo "building main file"
	gcc $(CFLAG) -c BinaryTree.c

BST.o: BST.c
	echo "building main file"
	gcc $(CFLAG) -c BST.c

clean:
	echo "deleting processes"
	rm *.o
	rm *.exe