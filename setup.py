from setuptools import setup, Extension

module = Extension('kemtest', sources=['kemtestmodule.c'])
minos_module = Extension('minos', sources=['minosmodule.c'])

setup(
    name='KemtestModule',
    version='1.0',
    description='Test wymiany kluczy ml-kem',
    ext_modules=[module, minos_module]
)