---
layout: default
title: PROXY
---
# Proxy

# APT

APT proxy setting in /etc/apt/apt.conf.

```bash
Acquire::http::Proxy "http://username:password@proxy_server:proxy_port";
```

Command line apt proxy arguments. Use -o

```bash
apt -o Acquire::http::Proxy="https://username:password@proxy_server:proxy_port" install/update
```

# PIP

Pip proxy setting in ~/.config/pip/pip.conf

```bash
[global]
proxy = http://username:password@proxy_server:proxy_port
```
Command line pip proxy arguments. Use --proxy.

```bash
pip install --proxy "https://username:password@proxy_server:proxy_port" [package_name]
```

# GIT

GIT proxy setting in ~/.gitconfig

```bash
[http]
    proxy = http://username:password@proxy_server:proxy_port
    sslverify = false
```

# CURL

curl proxy setting in ~/.curlrc
```bash
proxy="http://username:password@proxy_server:proxy_port"
```
Command line curl proxy arguments. Use -x or --proxy.

```bash
curl --proxy "http://username:password@proxy_server:proxy_port" "URL_of_interest"
```