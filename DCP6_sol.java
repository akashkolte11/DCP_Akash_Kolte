class Node{
    int data;
    Node left, right;
    
    public Node(int item){
        data = item;
        left = right = null;
    }
}
class Count{
    int count = 0;
}
class BinaryTree{
    Node root;
    Count ct = new Count();
    
    boolean countSingleRec(Node node, Count c){
        if(node==null){
            return true;
        }
        boolean left = countSingleRec(node.left, c);
        boolean right = countSingleRec(node.right, c);
        if(left==false || right==false){
            return false;
        }
        if(node.left != null && node.data != node.left.data){
            return false;
        }
        if(node.right != null && node.data != node.right.data){
            return false;
        }
        c.count++;
        return true;
    }
    int countSingle(){
        return countSingle(root);
    }
    int countSingle(Node node){
        countSingleRec(node, ct);
        return ct.count;
    }
    
    public static void main(String args[]){
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(0);
        tree.root.left = new Node(1);
        tree.root.right = new Node(0);
        tree.root.right.left = new Node(1);
        tree.root.right.right = new Node(0);
        tree.root.right.left.left = new Node(1);
        tree.root.right.left.right = new Node(1);
        
        System.out.println("Count of single valued subtrees is: " + tree.countSingle());
    }
}