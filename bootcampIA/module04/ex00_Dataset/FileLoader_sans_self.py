import pandas

class FileLoader(object):

	def load(path):
		'''Takes as an argument the file path of the dataset to load,
displays a message specifying the dimensions of the dataset (e.g. 340 x 500) and
returns the dataset loaded as a pandas.DataFrame.'''

		df = pandas.read_csv(path)
		dimensions = df.shape
		print(dimensions[0], 'x', dimensions[1])
		return df

	def display(df, n):
		'''Takes a pandas.DataFrame and an integer as arguments,
displays the first n rows of the dataset if n is positive, or the last n rows if n is
negative.'''
		if n > 0:
			print(df.head(n))
		# else:
		# 	print()


path = ('Death.csv')
FileLoader.load(path)
df = FileLoader.load(path)
n = 5
FileLoader.display(df, n)
