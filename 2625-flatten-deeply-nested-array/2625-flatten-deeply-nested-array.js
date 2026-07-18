/**
 * @param {Array} arr
 * @param {number} n
 * @return {Array}
 */
var flat = function(arr, n) {
    const result = [];

    function flatten(currentArray, depth) {
        for (const item of currentArray) {
            if (Array.isArray(item) && depth < n) {
                flatten(item, depth + 1);
            } else {
                result.push(item);
            }
        }
    }

    flatten(arr, 0);
    return result;
};