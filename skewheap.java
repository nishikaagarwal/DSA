import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
 

class SkewNode
{
    char element;
    SkewNode left, right;
 

    public SkewNode(char val)
    {
        this.element = val;
        this.left = null;
        this.right = null;
    }
}
 

class SkewHeap
{
    private SkewNode root;
    private int size;
 

    public SkewHeap()
    {
        root = null;
        size = 0;    
    }
 

    public boolean isEmpty()
    {
        return root == null;
    }
 

    public void clear()
    {
        root = null;
        size = 0;
    }
 

    public int getSize()
    {
        return size;
    }
 

    public void insert(char val)
    {
        root = merge(root, new SkewNode(val)); 
        size++ ;
    }
 

    public void remove() 
    {
        if (root == null)
            throw new NoSuchElementException("Element not found");
        root = merge(root.left, root.right);
        size--;
    }
 

    private SkewNode merge(SkewNode x, SkewNode y) 
    {
        if (x == null) 
            return y;
        if (y == null) 
            return x;
 
        if (x.element < y.element) 
        {
            SkewNode temp = x.left;
            x.left = merge(x.right, y);
            x.right = temp;
            return x;
        }
        else 
        {
            SkewNode temp = y.right;
            y.right = merge(y.left, x);
            y.left = temp;
            return y;
        }
    }
 

    public void displayHeap()
    {
        System.out.print("\nHeap : ");
        displayHeap(root, 4);
        System.out.println("\n");
    }
    private void displayHeap(SkewNode r, int depth)
    {
        if(r == null)
           return;
        Queue<SkewNode> q =new LinkedList<SkewNode>();
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
                SkewNode node = q.peek();
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

        /*if (r != null)
        {
            displayHeap(r.left);
            System.out.print((char)r.element +" ");
            displayHeap(r.right);
        }*/
    }    


    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Skew Heap \n\n");
 
   
        SkewHeap sh = new SkewHeap( );
                sh.insert('N'); 
                sh.insert('I'); 
                sh.insert('S'); 
                sh.insert('H'); 
                sh.insert('I'); 
                sh.insert('K');
                sh.insert('A');
                sh.insert('A');
                sh.insert('G');
                sh.insert('A');
                sh.insert('R');
                sh.insert('W');
                sh.insert('A');
                sh.insert('L');
                  
                sh.displayHeap();                
                System.out.println("");
                
                System.out.println("After first deletion");
                sh.remove();   
                sh.displayHeap();
                System.out.println("");
                
                System.out.println("After second deletion");
                sh.remove();   
                sh.displayHeap();
                System.out.println("");
             
                System.out.println("After third deletion");
                sh.remove();   
                sh.displayHeap();
                System.out.println("");
             
 
            }
}
