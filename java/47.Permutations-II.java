// AC but very slow, beacuse use ArrayList's contains method
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> rs = new ArrayList<>();
        if (nums == null || nums.length == 0) { return rs; }
        travel(nums, rs, new ArrayList<>(), new boolean[nums.length]);
        return rs;
    }

    private void travel(int[] nums, List<List<Integer>> rs, List<Integer> trs, boolean[] mark) {
        if (trs.size() == nums.length) {
            if (!rs.contains(trs)) {
                rs.add(new ArrayList(trs));
            }
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (mark[i]) { continue; }
            trs.add(nums[i]);
            mark[i] = true;
            travel(nums, rs, trs, mark);
            mark[i] = false;
            trs.remove(trs.size() - 1);
        }
    }
}
