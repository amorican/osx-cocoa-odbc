//
//  OdbcTest.m
//  Odbc
//
//  Created by Mikael Hakman on 2013-09-29.
//  Copyright (c) 2013 Mikael Hakman. All rights reserved.
//

#import "OdbcTest.h"
#import "Odbc/Odbc.h"

@interface OdbcTest () {
    
@protected
    
    OdbcConnection * connection;
}

@end

@implementation OdbcTest

- (void) run {
    
    [self connect];
    
    [self catalogs];
    
    [self schemas];
}

- (void) schemas {
    
    NSArray * schemas = [self->connection schemas];
    
    NSLog (@"%s schemas %@",__PRETTY_FUNCTION__,schemas);
}

- (void) catalogs {
    
    NSArray * catalogs = [self->connection catalogs];
    
    NSLog (@"%s catalogs %@",__PRETTY_FUNCTION__,catalogs);
}

- (void) connect {
    
    self->connection = [OdbcConnection new];
    
    [self->connection connect : @"testdb" user : @"root" password : nil];
}

@end
