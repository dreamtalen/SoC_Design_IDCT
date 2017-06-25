if __name__ == '__main__':
	for i in range(64):
		print 'case ' + str(8 + 4*i) + ':'
		print '    owner->r_reg' + str(i)+ ' = value[0]; break;'
		# print 'case ' + str(8 + 4*i) + ':'
		# print '    value[0] = owner->r_reg' + str(i)+ '; break;'