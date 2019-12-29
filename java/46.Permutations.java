class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> rs = new ArrayList<>();
        if (nums == null || nums.length == 0) { return rs; }
        List<Integer> trs = new ArrayList<>();
        travel(nums, rs, trs);
        return rs;
    }

    private void travel(int[] nums, List<List<Integer>> rs, List<Integer> trs) {
        if (trs.size() == nums.length) { 
            rs.add(new ArrayList(trs));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (trs.contains(nums[i])) { continue; }
            trs.add(nums[i]);
            travel(nums, rs, trs);
            trs.remove(trs.size() - 1);
        }
    }
}
