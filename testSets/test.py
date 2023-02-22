import unittest
import snakestats

class TestMeanFunction(unittest.TestCase):
    def test_empty_list(self):
        res=snakestats.mean([]), 0

    def test_one_element_list(self):
        res=snakestats.mean([1]), 1

    def test_two_element_list(self):
        res=snakestats.mean([1, 2]), 1.5

unittest.main(argv=['ignored', '-v'], exit=False)



class TestVarianceFunction(unittest.TestCase):
    def test_empty_list(self):
        res=snakestats.variance([]), 0

    def test_one_element_list(self):
        res = snakestats.variance([1]), 0

    def test_two_element_list(self):
        res=snakestats.variance([1, 2]), 0.6666666666666666

    unittest.main(argv=['ignored', '-v'], exit=False)


class TestStandardDeviationFunction(unittest.TestCase):
    def test_empty_list(self):
        res=snakestats.standard_deviation([]), 0

    def test_one_element_list(self):
        res=snakestats.standard_deviation([1]), 0

    def test_two_element_list(self):
        res=snakestats.standard_deviation([1, 2]), 0.816496580927726

unittest.main(argv=['ignored', '-v'], exit=False)