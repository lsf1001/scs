#include <utility>
#include <vector>
#include <string>

#include <lcscslib/lcscs.hpp>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wsign-compare"

using namespace lcscs;

CONTRACT test_ram_limit : public contract {
   public:
   using contract::contract;
   
      const uint32_t FIVE_MINUTES = 5*60;

      ACTION setentry( name payer, uint64_t from, uint64_t to, uint64_t size ) {
         const auto self = get_self();
         lcscs::print("test_ram_limit::setentry ", lcscs::name{self}, "\n");
         test_table table( self, self.value );
         for ( int key = from; key <=to; ++key ) {
            auto itr = table.find(key);
            if ( itr != table.end() ) {
               table.modify( itr, payer, [size](test& t) {
                  t.data.assign( size, (int8_t)size );
               });
            } else {
               table.emplace( payer, [key,size](test& t) {
                  t.key = key;
                  t.data.assign( size, (int8_t)size );
               });
            }
         }
      }

      ACTION rmentry( uint64_t from, uint64_t to ) {
         const auto self = get_self();
         lcscs::print("test_ram_limit::rmentry ", lcscs::name{self}, "\n");
         test_table table( self, self.value );
         for ( int key = from; key <=to; ++key ) {
            auto itr = table.find(key);
            lcscs_assert ( itr != table.end(), "could not find test_table entry" );
            table.erase(itr);
         }
      }

      ACTION printentry( uint64_t from, uint64_t to ) {
         const auto self = get_self();
         lcscs::print("test_ram_limit::printout ", lcscs::name{self}, ":");
         test_table table( self, self.value );
         for ( int key = from; key <= to; ++key ) {
            auto itr = table.find(key);
            lcscs::print("\nkey=", key);
            lcscs_assert ( itr != table.end(), "could not find test_table entry" );
            lcscs::print(" size=", itr->data.size());
         }
      }

   private:
      TABLE test {
         uint64_t            key;
         std::vector<int8_t> data;

         uint64_t primary_key()const { return key; }

         scsLIB_SERIALIZE( test, (key)(data) )
      };
      typedef lcscs::multi_index< "test.table"_n, test> test_table;
};

#pragma clang diagnostic pop

lcscs_DISPATCH( test_ram_limit, (setentry)(rmentry)(printentry) )
