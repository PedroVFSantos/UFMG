public interface TreeNode {
    int computeValue();
}

public class Leaf implements TreeNode {
    private final int value;

    public Leaf(int value) {
        this.value = value;
    }

    public int computeValue() {
        return value;
    }
}

public class Branch implements TreeNode {
    private final TreeNode left;
    private final TreeNode right;

    public Branch(TreeNode left, TreeNode right) {
        this.left = left;
        this.right = right;
    }

    public int computeValue() {
        return left.computeValue() + right.computeValue();
    }
}

