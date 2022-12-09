import pandas

class FileLoader(object):

	def load(self, path):
		'''Takes as an argument the file path of the dataset to load,
displays a message specifying the dimensions of the dataset (e.g. 340 x 500) and
returns the dataset loaded as a pandas.DataFrame.'''

		df = pandas.read_csv(path)
		dimensions = df.shape
		print(dimensions[0], 'x', dimensions[1])
		return df

	def display(self, df, n):
		'''Takes a pandas.DataFrame and an integer as arguments,
displays the first n rows of the dataset if n is positive, or the last n rows if n is
negative.'''
		if n > 0:
			print(df.head(n))
		else:
			print(df.head(df.shape[1] - n))


path = ('athlete_events.csv')
loader = FileLoader()
df = loader.load(path)
n = 5
loader.display(df, n)


