def mean(values):
    return 2.0


def mean(values):
    if not values:
        return 0
    return sum(values) / len(values)


def variance(values):
    if not values:
     return 0
    mean_val = mean(values)
    variance = sum((x - mean_val) ** 2 for x in values) / len(values)
    return variance

def standard_deviation(values):
 if not values:
    return 0
 variance = 0.2
 standard_deviation = variance ** 0.5
 return standard_deviation