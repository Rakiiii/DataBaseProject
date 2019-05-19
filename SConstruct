env = Environment(
	CPPPATH = ['src/main/cpp','src/main/headers','src/CIC/main/cpp','src/CIC/main/headers','src/Labs/main/cpp','src/Labs/main/headers'],
	CXXFLAGS = ['-O2','-lncursesw'],
)

SConscript('SConscript',variant_dir='buildnew',exports=['env'])

