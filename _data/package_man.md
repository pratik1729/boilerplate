---
layout: default
title: BASH
---
# Package Managers

# apt

| Command                     | description                                                                                                                                                    |
| --------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| apt update                  | download package information from all sources                                                                                                                  |
| apt upgrade                 | install available upgrades of all packages currently installed                                                                                                 |
| apt install                 | installs a package                                                                                                                                             |
| apt remove                  | removes the package                                                                                                                                            |
| apt purge                   | removes packages and the leftover data or configuration files                                                                                                  |
| apt search                  | search for a given regex in the list of available packages                                                                                                     |
| apt show                    | show information about the given package including its dependencies, installation and download size                                                            |
| apt list                    | list packages satisfying certain criteria: \--installed, \--upgradable, \--all-versions                                                                        |
| apt autoremove              | removes packages that were automatically installed to satisfy dependencies for other packages and are now longer needed                                        |
| apt edit-sources            | lets you edit sources                                                                                                                                          |
| apt-key add [filename ⎮ - ] | add key to authenticate packages. But it is adviced to place the keyring in /etc/apt/trusted.gpg.d/ with "gpg" or "asc" file extension. GPG=GNU privacy guard. |
| apt-key list   | list all keys added |
| apt-key del [key ID] | Delete using key ID |

# dpkg

| Command                           | description                                                                      |
| --------------------------------- | -------------------------------------------------------------------------------- |
| dpkg -l                           | list all packages installed                                                      |
| dpkg -L wget                      | list files installed in the wget package                                         |
| dpkg -p wget                      | show information about an installed package                                      |
| dpkg -I [.deb file]               | show information about a package file                                            |
| dpkg -c [.deb file]               | list files in a package file                                                     |
| dpkg -S /etc/init/networking.conf | show what package owns the file                                                  |
| dpkg -s wget                      | show the status of the package                                                   |
| dpkg -V package                   | verify the installed package's integrity                                         |
| dpkg -i foobar.deb                | used for installing or upgrading the foobar package                              |
| dpkg -r package                   | remove all of an installed package except for its configuration files            |
| dpkg -P package                   | remove all of an installed package, including its configuration files. -P=purge. |
