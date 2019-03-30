void dfs(vector<int>& candidates, vector<int>& outcome, int target, vector<vector<int>> &result) {
	int current_sum = 0;
	for (auto each : outcome) {
		current_sum += each;
	}
	if (current_sum == target) {
		result.push_back(outcome);
		return;
	}
	for (auto num : candidates) {
		if (outcome.empty() || num >= outcome.back()) {
			outcome.push_back(num);
			if (num + current_sum == target) {
				result.push_back(outcome);
			}
			if (num + current_sum < target) {
				dfs(candidates, outcome, target, result);
			}
			outcome.pop_back();
		}
	}
	return;
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	if (candidates.size() <= 0)
		return {};
	vector<int> out;
	vector<vector<int>> re;
	dfs(candidates, out, target, re);
	return re;
}