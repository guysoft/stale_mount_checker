Stale file checker
==================

Simple python binding to stat, in order to check for stale nfs mount.
This code is a 20 min clone and edit of `python-spam-module <https://github.com/mdobson/python-spam-module>`_ which is part of the `python doc examples <https://docs.python.org/2/extending/extending.html>`_.


Usage
=====

Has a simple function::

    import stale
    stale.is_stale("/mnt")


The code is taken from `here <http://stackoverflow.com/questions/1643347/is-there-a-good-way-to-detect-a-stale-nfs-mount>`_


