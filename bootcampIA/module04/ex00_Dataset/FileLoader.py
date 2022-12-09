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


path = ('Death.csv')
loader = FileLoader()
df = loader.load(path)
n = 5
loader.display(df, n)


#si au lieu du return on ecrit self.df = df dans load alors on peut reutiliser self.df dans display!
#mais concretement ici self ne nous sert a rien puisque df fait deja partie de nos parametres de la deuxieme fonction.
#loader est le self (loader est le nouvel objet)
