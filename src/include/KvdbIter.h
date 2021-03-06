#ifndef _HLKVDS_KVDBITER_H_
#define _HLKVDS_KVDBITER_H_

#include <string>
#include "hlkvds/Iterator.h"

namespace hlkvds {

class IndexManager;
class DataStor;
class HashEntry;

class KvdbIter : public Iterator {
public:
    KvdbIter(IndexManager* im, DataStor* ds);
    ~KvdbIter();

    virtual void SeekToFirst() override;
    virtual void SeekToLast() override;
    virtual void Seek(const char* key) override;
    virtual void Next() override;
    virtual void Prev() override;

    virtual std::string Key() override;
    virtual std::string Value() override;

    virtual bool Valid() const override;
    virtual Status status() const override;

private:
    IndexManager *idxMgr_;
    DataStor* dataStor_;
    bool valid_;
    HashEntry *hashEntry_;
    Status status_;
    int htSize_;
    int hashTableCur_;
    int entryListCur_;
};
} 

#endif // #ifndef _HLKVDS_KVDBITER_H_
