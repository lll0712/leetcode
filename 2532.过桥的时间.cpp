/*
 * @lc app=leetcode.cn id=2532 lang=cpp
 *
 * [2532] 过桥的时间
 *
 * https://leetcode.cn/problems/time-to-cross-a-bridge/description/
 *
 * algorithms
 * Hard (51.68%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 4.1K
 * Testcase Example:  '1\n3\n[[1,1,2,1],[1,1,3,1],[1,1,4,1]]'
 *
 * 共有 k 位工人计划将 n 个箱子从旧仓库移动到新仓库。给你两个整数 n 和 k，以及一个二维整数数组 time ，数组的大小为 k x 4 ，其中
 * time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi] 。
 * 
 * 一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 k 位工人都在桥的左侧等待。为了移动这些箱子，第 i
 * 位工人（下标从 0 开始）可以：
 * 
 * 
 * 从左岸（新仓库）跨过桥到右岸（旧仓库），用时 leftToRighti 分钟。
 * 从旧仓库选择一个箱子，并返回到桥边，用时 pickOldi 分钟。不同工人可以同时搬起所选的箱子。
 * 从右岸（旧仓库）跨过桥到左岸（新仓库），用时 rightToLefti 分钟。
 * 将箱子放入新仓库，并返回到桥边，用时 putNewi 分钟。不同工人可以同时放下所选的箱子。
 * 
 * 
 * 如果满足下面任一条件，则认为工人 i 的 效率低于 工人 j ：
 * 
 * 
 * leftToRighti + rightToLefti > leftToRightj + rightToLeftj
 * leftToRighti + rightToLefti == leftToRightj + rightToLeftj 且 i > j
 * 
 * 
 * 工人通过桥时需要遵循以下规则：
 * 
 * 
 * 如果工人 x 到达桥边时，工人 y 正在过桥，那么工人 x 需要在桥边等待。
 * 如果没有正在过桥的工人，那么在桥右边等待的工人可以先过桥。如果同时有多个工人在右边等待，那么 效率最低 的工人会先过桥。
 * 如果没有正在过桥的工人，且桥右边也没有在等待的工人，同时旧仓库还剩下至少一个箱子需要搬运，此时在桥左边的工人可以过桥。如果同时有多个工人在左边等待，那么
 * 效率最低 的工人会先过桥。
 * 
 * 
 * 所有 n 个盒子都需要放入新仓库，请你返回最后一个搬运箱子的工人 到达河左岸 的时间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
 * 输出：6
 * 解释：
 * 从 0 到 1 ：工人 2 从左岸过桥到达右岸。
 * 从 1 到 2 ：工人 2 从旧仓库搬起一个箱子。
 * 从 2 到 6 ：工人 2 从右岸过桥到达左岸。
 * 从 6 到 7 ：工人 2 将箱子放入新仓库。
 * 整个过程在 7 分钟后结束。因为问题关注的是最后一个工人到达左岸的时间，所以返回 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3, k = 2, time = [[1,9,1,8],[10,10,10,10]]
 * 输出：50
 * 解释：
 * 从 0 到 10 ：工人 1 从左岸过桥到达右岸。
 * 从 10 到 20 ：工人 1 从旧仓库搬起一个箱子。
 * 从 10 到 11 ：工人 0 从左岸过桥到达右岸。
 * 从 11 到 20 ：工人 0 从旧仓库搬起一个箱子。
 * 从 20 到 30 ：工人 1 从右岸过桥到达左岸。
 * 从 30 到 40 ：工人 1 将箱子放入新仓库。
 * 从 30 到 31 ：工人 0 从右岸过桥到达左岸。
 * 从 31 到 39 ：工人 0 将箱子放入新仓库。
 * 从 39 到 40 ：工人 0 从左岸过桥到达右岸。
 * 从 40 到 49 ：工人 0 从旧仓库搬起一个箱子。
 * 从 49 到 50 ：工人 0 从右岸过桥到达左岸。
 * 从 50 到 58 ：工人 0 将箱子放入新仓库。
 * 整个过程在 58 分钟后结束。因为问题关注的是最后一个工人到达左岸的时间，所以返回 50 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, k <= 10^4
 * time.length == k
 * time[i].length == 4
 * 1 <= leftToRighti, pickOldi, rightToLefti, putNewi <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    using PII = pair<int, int>;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // 定义等待中的工人优先级比较规则，时间总和越高，效率越低，优先级越低，越优先被取出
        auto wait_priority_cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];
            int time_y = time[y][0] + time[y][2];
            return time_x != time_y ? time_x < time_y : x < y;
        };

        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp), wait_right(wait_priority_cmp);

        priority_queue<PII, vector<PII>, greater<PII>> work_left, work_right;

        int remain = n, cur_time = 0;
        for (int i = 0; i < k; i++) {
            wait_left.push(i);
        }
        while (remain > 0 || !work_right.empty() || !wait_right.empty()) {
            // 1. 若 work_left 或 work_right 中的工人完成工作，则将他们取出，并分别放置到 wait_left 和 wait_right 中。
            while (!work_left.empty() && work_left.top().first <= cur_time) {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top().first <= cur_time) {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            if (!wait_right.empty()) {
                // 2. 若右侧有工人在等待，则取出优先级最低的工人并过桥
                int id = wait_right.top();
                wait_right.pop();
                cur_time += time[id][2];
                work_left.push({cur_time + time[id][3], id});
            } else if (remain > 0 && !wait_left.empty()) {
                // 3. 若右侧还有箱子，并且左侧有工人在等待，则取出优先级最低的工人并过桥
                int id = wait_left.top();
                wait_left.pop();
                cur_time += time[id][0];
                work_right.push({cur_time + time[id][1], id});
                remain--;
            } else {
                // 4. 否则，没有人需要过桥，时间过渡到 work_left 和 work_right 中的最早完成时间
                int next_time = INT_MAX;
                if (!work_left.empty()) {
                    next_time = min(next_time, work_left.top().first);
                }
                if (!work_right.empty()) {
                    next_time = min(next_time, work_right.top().first);
                }
                if (next_time != INT_MAX) {
                    cur_time = max(next_time, cur_time);
                }
            }
        }
        return cur_time;
    }
};

// @lc code=end

