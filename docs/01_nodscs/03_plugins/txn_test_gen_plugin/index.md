
## Description

The `txn_test_gen_plugin` is used for transaction test purposes.

[[info | For More Information]]
For more information, check the [txn_test_gen_plugin/README.md](https://github.com/lcscs/scs/blob/develop/plugins/txn_test_gen_plugin/README.md) on the lcscs/scs repository.

## Usage

```console
# config.ini
plugin = lcscs::txn_test_gen_plugin
[options]
```
```sh
# command-line
nodscs ... --plugin lcscs::txn_test_gen_plugin [options]
```

## Options

These can be specified from both the `nodscs` command-line or the `config.ini` file:

```console
Config Options for lcscs::txn_test_gen_plugin:
  --txn-reference-block-lag arg (=0)    Lag in number of blocks from the head 
                                        block when selecting the reference 
                                        block for transactions (-1 means Last 
                                        Irreversible Block)
  --txn-test-gen-threads arg (=2)       Number of worker threads in 
                                        txn_test_gen thread pool
  --txn-test-gen-account-prefix arg (=txn.test.)
                                        Prefix to use for accounts generated 
                                        and used by this plugin
```

## Dependencies

None
