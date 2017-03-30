from distutils.core import setup, Extension

spam_module = Extension('stale',
		sources = ['stale.cpp'])

setup ( name = 'StaleDetector',
	version = '1.0',
	description = 'Sample module.',
	ext_modules = [ spam_module ])
