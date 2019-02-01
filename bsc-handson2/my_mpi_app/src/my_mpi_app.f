C  Ping-pong with MPI + I/O

      include 'mpif.h'

      integer BUFFSIZE, MSGSIZE, error, rank, wsize, dest, i, e, ir
      integer status(MPI_STATUS_SIZE), NITERS, retsize
      parameter (BUFFSIZE=100000, MSGSIZE=10000, NITERS=10)
      integer*1 buff, foo, sndmsg, rcvmsg
      dimension buff(BUFFSIZE)
      dimension foo(1)
      dimension sndmsg(MSGSIZE)
      dimension rcvmsg(MSGSIZE)
      real*8 r, r2

      call MPI_Init(error)
      if (error .ne. MPI_SUCCESS) stop
      call MPI_Comm_rank(MPI_COMM_WORLD, rank, error)
      call MPI_Comm_size(MPI_COMM_WORLD, wsize, error)
      call MPI_Buffer_attach(buff, buffsize, error)

      do e=1, NITERS
        call do_work (r)
        do i=1, 9

            if (rank .eq. 0) then
                call MPI_Bsend(r, 1, MPI_REAL8, rank+1, rank, 
     1          MPI_COMM_WORLD, error)
            else
               call MPI_Recv(r2, 1, MPI_REAL8, MPI_ANY_SOURCE, 
     1         MPI_ANY_TAG,MPI_COMM_WORLD, status, error)
               if (rank .lt. (wsize - 1)) then
                 call MPI_Bsend(r, 1, MPI_REAL8, rank+1, rank, 
     1           MPI_COMM_WORLD, error)
               end if
            end if 
            call MPI_Barrier(MPI_COMM_WORLD, error)

            call do_less_work (r)

            if (MOD(rank,4) .eq. 0) then
               do ir=0, wsize-1
                 if (MOD(ir,4) .ne. 0) then
                   call MPI_Sendrecv(sndmsg, MSGSIZE, MPI_INTEGER1,ir,
     1               rank, rcvmsg, MSGSIZE, MPI_INTEGER1,MPI_ANY_SOURCE,
     1               MPI_ANY_TAG, MPI_COMM_WORLD, status, error)
                 end if
               end do
            else
              do ir=0, 5 
                call MPI_Sendrecv(sndmsg, MSGSIZE, MPI_INTEGER1,ir*4,
     1          rank, rcvmsg, MSGSIZE, MPI_INTEGER1,ir*4 ,
     1          MPI_ANY_TAG, MPI_COMM_WORLD, status, error)
              end do
            end if 

        call do_less_work (r)

        end do
        
        do ir=0,9
          call Compute((ir)*12-24, rank, r)
            if (rank .lt. (wsize-1)) then
                call MPI_ISend(r, 1, MPI_REAL8, rank+1, rank, 
     1          MPI_COMM_WORLD, r2, error)
            end if
            if (rank .gt. 0) then
              call MPI_Recv(r2, 1, MPI_REAL8, rank-1, 
     1         MPI_ANY_TAG,MPI_COMM_WORLD, status, error)
            end if
        enddo
        call Compute(24, rank, r)
        call MPI_Barrier(MPI_COMM_WORLD, error)
      end do


      call MPI_Buffer_detach(foo, retsize, error)

      call MPI_Finalize(error)
      stop
      end


      subroutine Compute (bsize, rank, r)
         integer :: bsize, rank
         real*8 :: r

         integer :: n, i
         real*8 :: h, tmp

         tmp = 0
         n = 300*300
         if (bsize .eq. rank) then
            n = n + (rank +1)*3333
         end if
         do i=1, n
             x = h * (i - 0.5)
             tmp = tmp + (4.0 / (1.0 + x*x))
         end do
         r = tmp

         return
      end
