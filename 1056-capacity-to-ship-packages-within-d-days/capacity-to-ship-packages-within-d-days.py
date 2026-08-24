class Solution(object):
    def shipWithinDays(self, weights, days):
      low = max(weights)
      high = sum(weights)

      while low <= high:
        mid = low + (high - low) // 2

        d = 1
        total = 0

        for w in weights:
            if total + w > mid:
                d += 1
                total = 0

            total += w

        if d <= days:
            high = mid-1
        else:
            low = mid +1

      return low
           

        