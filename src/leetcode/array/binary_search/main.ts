function search(nums: number[], target: number) {
    let left: number = 0;
    let right: number = nums.length - 1;
    while (left <= right) {
        let mid: number = Math.floor((left + right) / 2);
        if (nums[mid] === target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

console.log(search([1, 2, 3, 4, 5], 3))