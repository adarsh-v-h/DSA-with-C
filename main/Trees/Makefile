CFLAG := -Wno-implicit-function-declaration

tree: final
final: c_utils.o BinaryTree.o
	echo "building final"
	gcc -o final BinaryTree.o c_utils.o

c_utils.o: c_utils.c
	echo "building utils"
	gcc $(CFLAG) -c c_utils.c

BinaryTree.o: BinaryTree.c
	echo "building main file"
	gcc $(CFLAG) -c BinaryTree.c

clean:
	echo "deleting processes"
	rm *.o
	rm *.exe