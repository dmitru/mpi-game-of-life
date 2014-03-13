
import random
from optparse import OptionParser
from sys import argv, exit
 
if __name__ == '__main__':
		parser = OptionParser()
		parser.add_option('-n', dest='n', default=10)
		parser.add_option('-m', dest='m', default=10)
		parser.add_option('-o', '--output', dest='output_file', default='field.txt')
        
		(options, args) = parser.parse_args()
		n = int(options.n)
		m = int(options.m)

		f = open(options.output_file, 'w')
		field_elements_generator = (random.randint(0, 1) for _ in range(n * m))
		
		print(n, m, file=f)
		for _ in range(n):
			for _ in range(m):
				print(field_elements_generator.__next__(), file=f, end=' ')
			print(file=f)
		f.close()
        
        
