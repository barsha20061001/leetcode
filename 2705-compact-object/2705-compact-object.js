/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        const result = [];

        for (const value of obj) {
            if (!value) continue;

            if (typeof value === "object") {
                result.push(compactObject(value));
            } else {
                result.push(value);
            }
        }

        return result;
    }

    const result = {};

    for (const key in obj) {
        const value = obj[key];

        if (!value) continue;

        if (typeof value === "object") {
            result[key] = compactObject(value);
        } else {
            result[key] = value;
        }
    }

    return result;
};