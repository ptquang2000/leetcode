#ifndef UTILS_ARRAY_H
#define UTILS_ARRAY_H

#define array_foreach(it, arr) for (typeof(arr.data) it = &((arr).data[0]); (it) < &((arr).data[(arr).len]); (it)++)

#define darray_foreach(it, arr, darr)                                                                                  \
        for (typeof(darr.data) arr = &((darr).data[0]); (arr) < &((darr).data[(darr).nr]); (arr)++)                    \
                for (typeof(*arr) it = &((arr)[0][0]); (it) < &((arr)[0][(darr).len[arr - (darr).data]]); (it)++)

#define array_zip(it1, arr1, it2, arr2)                                                                                \
        for (typeof(arr1.data) it1 = &((arr1).data[0]), it2 = &((arr2).data[0]); (it1) < &((arr1).data[(arr1).len]);   \
             (it1)++, (it2)++)

#define darray_zip(it1, darr1, it2, darr2)                                                                             \
        for (typeof(darr1.data) arr1 = &((darr1).data[0]), arr2 = &((darr2).data[0]);                                  \
             (arr1) < &((darr1).data[(darr1).nr]); (arr1)++, (arr2)++)                                                 \
                for (typeof(*arr1) it1 = &((arr1)[0][0]), it2 = &((arr2)[0][0]);                                       \
                     (it1) < &((arr1)[0][(darr1).len[arr1 - (darr1).data]]); (it1)++, (it2)++)

#endif
