## Goal

Undelegate resource for an account or application

Beware that only the account which originally delegated resource can undelegate

## Before you begin

* Install the currently supported version of `clscs`

* Ensure the reference system contracts from `lcscs.contracts` repository is deployed and used to manage system resources

* Understand the following:
  * What is an account
  * What is network bandwidth
  * What is CPU bandwidth

## Steps

Undelegate 0.01 SYS CPU bandwidth form from account `alice` back to account `bob`:

```sh
clscs system undelegatebw bob alice "0 SYS" "0.01 SYS"
```

You should see something below:

```console
executed transaction: e7e7edb6c5556de933f9d663fea8b4a9cd56ece6ff2cebf056ddd0835efa6606  184 bytes  452 us
#         lcscs <= lcscs::undelegatebw          {"from":"alice","receiver":"bob","unstake_net_quantity":"0.0000 scs","unstake_cpu_qu...
warning: transaction executed locally, but may not be confirmed by the network yet         ]
```
