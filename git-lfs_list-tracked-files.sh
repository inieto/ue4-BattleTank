#!/bin/bash
git ls-files ':(attr:filter=lfs)' | egrep "uasset|umap"
