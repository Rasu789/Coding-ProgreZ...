#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 11

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

void send_all_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office *src = &source->offices[source_office_index];
    post_office *tgt = &target->offices[target_office_index];
    
    package *accepted = malloc(sizeof(package) * (src->packages_count + tgt->packages_count));
    package *rejected = malloc(sizeof(package) * src->packages_count);
    
    int rejected_count = 0;
    int new_tgt_count = tgt->packages_count;
    
    // Copy existing target packages
    for(int i = 0; i < tgt->packages_count; i++) accepted[i] = tgt->packages[i];

    for (int i = 0; i < src->packages_count; i++) {
        if (src->packages[i].weight >= tgt->min_weight && src->packages[i].weight <= tgt->max_weight) {
            accepted[new_tgt_count++] = src->packages[i];
        } else {
            rejected[rejected_count++] = src->packages[i];
        }
    }

    free(tgt->packages);
    tgt->packages = realloc(accepted, sizeof(package) * new_tgt_count);
    tgt->packages_count = new_tgt_count;

    free(src->packages);
    src->packages = realloc(rejected, sizeof(package) * rejected_count);
    src->packages_count = rejected_count;
}

town town_with_most_packages(town* towns, int towns_count) {
    int max_pkgs = -1;
    int ans_idx = 0;
    for (int i = 0; i < towns_count; i++) {
        int current_pkgs = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            current_pkgs += towns[i].offices[j].packages_count;
        }
        if (current_pkgs > max_pkgs) {
            max_pkgs = current_pkgs;
            ans_idx = i;
        }
    }
    return towns[ans_idx];
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) return &towns[i];
    }
    return NULL;
}

int main() {
    int towns_count;
    if (scanf("%d", &towns_count) != 1) return 0;
    town* towns = malloc(sizeof(town) * towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d %d %d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    while (queries--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char name[MAX_STRING_LENGTH];
            scanf("%s", name);
            town* t = find_town(towns, towns_count, name);
            print_all_packages(*t);
        } else if (type == 2) {
            char source_name[MAX_STRING_LENGTH], target_name[MAX_STRING_LENGTH];
            int source_idx, target_idx;
            scanf("%s %d %s %d", source_name, &source_idx, target_name, &target_idx);
            town* src = find_town(towns, towns_count, source_name);
            town* tgt = find_town(towns, towns_count, target_name);
            send_all_packages(src, source_idx, tgt, target_idx);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }
    return 0;
}
