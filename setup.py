import sys
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension
 
VERSION = "0.1"
 
if __name__ == '__main__':
    hello = Extension('hello', sources = ['hello.cpp'])
    setup(name = "hello", version = VERSION, url = "example.org",
    	description = "Python3 Example", long_description = """A super simple C++/Python example.""",
    	license = "BSD", packages = [], ext_modules = [hello])

