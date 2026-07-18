var TimeLimitedCache = function() {
    this.cache = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const current = this.cache.get(key);
    const existed = current !== undefined && current.expiry > Date.now();

    this.cache.set(key, {
        value: value,
        expiry: Date.now() + duration
    });

    return existed;
};

/**
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    const entry = this.cache.get(key);

    if (entry === undefined || entry.expiry <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return entry.value;
};

/**
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    const currentTime = Date.now();

    for (const [key, entry] of this.cache) {
        if (entry.expiry <= currentTime) {
            this.cache.delete(key);
        }
    }

    return this.cache.size;
};