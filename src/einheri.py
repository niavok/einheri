#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# Copyright (C) 2010 Frédéric Bertolus.
#
# This file is part of Einheri.
#
# Einheri is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Einheri is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Einheri.  If not, see <http://www.gnu.org/licenses/>.

import sys
from einherilib.client.einheri_client import EinheriClient
from einherilib.common.config import Config
def main():

    config = Config()


    client = EinheriClient()
    client.run()

if __name__ == '__main__':
    main()
