// fast, beacuse simply skip same combination
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> rs = new ArrayList<>();
        if (nums == null || nums.length == 0) { return rs; }
        Arrays.sort(nums);
        travel(nums, rs, new ArrayList<>(), new boolean[nums.length]);
        return rs;
    }

    private void travel(int[] nums, List<List<Integer>> rs, List<Integer> trs, boolean[] mark) {
        if (trs.size() == nums.length) {
            rs.add(new ArrayList(trs));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (mark[i]) { continue; }
            if (i > 0 && nums[i] == nums[i-1] && !mark[i-1]) { continue; }
            trs.add(nums[i]);
            mark[i] = true;
            travel(nums, rs, trs, mark);
            mark[i] = false;
            trs.remove(trs.size() - 1);
        }
    }
}
