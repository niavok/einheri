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

"""The configuration of einheri.
Config is the general class.
config is the current configuration object."""

from einherilib.common.config.config_lib import Config
from einherilib.common.config.einheri_client_config import config as client_config
from einherilib.common.config.einheri_server_config import config as server_config
