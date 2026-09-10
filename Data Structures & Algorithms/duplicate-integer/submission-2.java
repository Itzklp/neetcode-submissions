class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet<Integer> ht = new HashSet<>();

        for (int i : nums) {
            ht.add(i);
        }

        return nums.length != ht.size();
    }
}