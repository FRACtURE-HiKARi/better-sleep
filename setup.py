from setuptools import setup, Extension

# Define the C++ extension
better_sleep_backend = Extension(
    'better_sleep_backend',
    sources=['better_sleep/pyEntrance.cpp'],
    include_dirs=['better_sleep'],
    extra_compile_args=['-std=c++11', '-fPIC'],
    libraries=[],  # Add any required libraries here
    extra_link_args=[],
)

# Package setup
setup(
    name='better_sleep',
    version='1.0.0',
    description='A Python package for CPU-intensive sleep using multiple threads.',
    long_description=open('README.md', encoding='utf-8').read(),
    long_description_content_type='text/markdown',
    author='FRACtURE-HiKARi',
    author_email='fracture.hikarii@gmail.com',
    url='https://github.com/FRACtURE-HiKARi/better_sleep',
    packages=['better_sleep'],
    ext_modules=[better_sleep_backend],
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)