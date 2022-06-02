import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

class LeftHeapNode {
	char element, sValue;
	LeftHeapNode left, right;

	public LeftHeapNode(char ele) {
		this(ele, null, null);
	}

	public LeftHeapNode(char ele, LeftHeapNode left, LeftHeapNode right) {
		this.element = ele;
		this.left = left;
		this.right = right;
		this.sValue = '\0';
	}
}

class LeftistHeap {
	private LeftHeapNode root;

	public LeftistHeap() {
		root = null;
	}

	public boolean isEmpty() {
		return root == null;
	}

	public void clear() {
		root = null;
	}

	public void insert(char x) {
		root = merge(new LeftHeapNode(x), root);
	}

	public void merge(LeftistHeap rhs) {
		if (this == rhs)
			return;
		root = merge(root, rhs.root);
		rhs.root = null;
	}

	private LeftHeapNode merge(LeftHeapNode x, LeftHeapNode y) {
		if (x == null)
			return y;
		if (y == null)
			return x;
		if (x.element > y.element) {
			LeftHeapNode temp = x;
			x = y;
			y = temp;
		}

		x.right = merge(x.right, y);

		if (x.left == null) {
			x.left = x.right;
			x.right = null;
		} else {
			if (x.left.sValue < x.right.sValue) {
				LeftHeapNode temp = x.left;
				x.left = x.right;
				x.right = temp;
			}
			x.sValue = (char)(x.right.sValue + 1);
		}
		return x;
	}

	public int deleteMin() {
		if (isEmpty())
			return -1;
		int minItem = root.element;
		root = merge(root.left, root.right);
		return minItem;
	}

	public void display() {
		display(root, 4);
		System.out.println();
	}

	private void display(LeftHeapNode r, int depth) {
	    if(r == null)
           return;
        Queue<LeftHeapNode> q =new LinkedList<LeftHeapNode>();
        q.add(r);               
	    while(true)
        {               
        int nodeCount = q.size();
        if(nodeCount == 0)
            break;
        for(int i=0; i<depth; i++) {
          System.out.print("  ");
        }
        while(nodeCount > 0)
        {    
            LeftHeapNode node = q.peek();
            System.out.print("("+node.element + ")");

            q.remove();

            if(node.left != null)
                q.add(node.left);
            if(node.right != null)
                q.add(node.right);

            if(nodeCount>1){
               System.out.print(", ");
            }
            nodeCount--;    
        }
        depth--;
        System.out.println();
    }
		
	}


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		LeftistHeap lh = new LeftistHeap();

		char ch;

				lh.insert('N');
				lh.insert('I');
				lh.insert('S');
				lh.insert('H');
				lh.insert('I');
				lh.insert('K');
				lh.insert('A');
				lh.insert('A');
				lh.insert('G');
				lh.insert('A');
				lh.insert('R');
				lh.insert('W');
				lh.insert('A');
				lh.insert('L');
				
 
				
				
			
			lh.display();

			
			System.out.println("Deleting min");
			System.out.println("After first deletion\n");
			lh.deleteMin();
			lh.display();
			System.out.println();
			
			System.out.println("Deleting min\n");
			System.out.println("After second deletion\n");
			lh.deleteMin();
			lh.display();
			System.out.println();
			
			System.out.println("Deleting min\n");
			System.out.println("After third deletion\n");
			lh.deleteMin();
			lh.display();
			System.out.println();
	}
}

